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
bool vis[1009][1009];
string arr[1009];
int n, m, ret = 0, rj = 0, ri = 0;
bool validate(int i, int j) {
	return (i >= 0 && i < n && j >= 0 && j < m) ? 1 : 0;
}
void DFS(int i, int j, int r) {
	if (arr[i][j] == '#')
		return;
	if (r > ret) {
		ret = r, ri = i, rj = j;
	}
	FO(q,0,4) {
		int DI = i + di[q], DJ = j + dj[q];
		if (validate(DI, DJ) && vis[DI][DJ] == 0 && arr[DI][DJ] == '.') {
			vis[DI][DJ] = 1;
			DFS(DI, DJ, r + 1);
		}
	}
}
int main() {
	int co;
	scanf("%d", &co);
	while (co--) {
		ret = n = m = ri = rj = 0;
		scanf("%d%d", &m, &n);
		memset(vis, 0, sizeof vis);
		FO(i,0,n)
			cin >> arr[i];
		FO(i,0,n)
			FO(r,0,SZ(arr[i])) {
//				cout << i << " " << r << " " << arr[i][r] << " " << vis[i][r]
//						<< endl;
				if (vis[i][r] == 0 && arr[i][r] == '.') {
					DFS(i, r, 0);
					memset(vis, 0, sizeof vis);
					DFS(ri, rj, 0);
				}
			}
		cout << "Maximum rope length is " << ret << "." << endl;
	}
	return 0;
}
