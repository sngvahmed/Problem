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
vector<vector<pair<int, int> > > arr;
bool vis[2002];
int mx = 0;
int gl = 0;
int main() {
	int n, m;
	cin >> n >> m;
	string arr[n];
	int ret = 0;
	FO(i,0,n)
		cin >> arr[i];
	FO(i,0,n) {
		FO(e,0,m) {
			if (arr[i][e] == 'W') {
				int mx1 = 0, mx2 = 0, mx3 = 0, mx4 = 0;
				if (e < m - 1 && arr[i][e + 1] == 'P')
					mx1++;
				if (e > 0 && arr[i][e - 1] == 'P')
					mx2++;
				if (i > 0 && arr[i - 1][e] == 'P')
					mx3++;
				if (i < n - 1 && arr[i + 1][e] == 'P')
					mx4++;
				ret += max(mx1, max(mx2, max(mx3, mx4)));
			}
		}
	}
	cout << ret << endl;
	return 0;
}
