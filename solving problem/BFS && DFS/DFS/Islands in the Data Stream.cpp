#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
#include <memory.h>
#include <climits>
#include <math.h>

using namespace std;

#define FO(i, a, x) for(int i = a; i < (int)x; i++)
#define FOR(i, x) FO(i, 0, x)
#define RO(i, a, x) for(int i = a; i >= x; i--)
#define ROF(i, x) for(int i = x; i >= 0; i--)
#define FORIT(it, x) for(typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define FOUND(s, x) find(all(s), x) != s.end()
#define NOTFOUND(s, x) find(all(s), x) == s.end()
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MMS(x, v) memset(x, v, sizeof(x))
#define SQ(x) (x) * (x)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<string> vs;
typedef vector<int> vi;
int di[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dj[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
int ret = 0;
int arr[16];
bool validate(string sum) {
	int i = 1;
	char I = sum[0], J = sum[SZ(sum) - 1];
	while (i < SZ(sum) - 1) {
		if (sum[i] <= I || sum[i] <= J)
			return 0;
		i++;
	}
	return 1;
}
void DFS(int i, string sum, map<string, int> vis) {
	if (SZ(sum) > 2 && validate(sum) && vis[sum] == 0) {
		ret++, vis[sum] = 1;
	}
	if (i == 16) {
		return;
	}
	DFS(i + 1, sum + char(arr[i] + '0'), vis);
}
void Generate() {
	FO(i,1,16) {
		DFS(i, "", map<string, int>());
	}
}
int main() {
	int co;
	scanf("%d", &co);
	while (co--) {
		ret = 0;
		FO(i,0,16)
			scanf("%d", &arr[i]);
		Generate();
		cout << arr[0] << " " << ret << endl;
	}
	return 0;
}
