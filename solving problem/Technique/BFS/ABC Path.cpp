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
bool vis[55][55];
char src[55][55];
int DP[55][55];
int n, m;
int BFS(int i, int j) {
	memset(vis, 0, sizeof(vis));
	queue<pair<int, int> > Q;
	Q.push(make_pair(i, j));
	vis[i][j] = 1;
	int lvl = 0;
	while (!Q.empty()) {
		int sz = Q.size();
		while (sz--) {
			int ri = Q.front().first;
			int rj = Q.front().second;
			Q.pop();
			FO(e,0,8) {
				int qi = ri + di[e], qj = rj + dj[e];
				if (qi >= n || qi < 0 || qj >= m || qj < 0 || vis[qi][qj])
					continue;
				char x = src[qi][qj];
				if (abs(int(x) - int(src[ri][rj])) == 1) {
					vis[qi][qj] = 1;
					Q.push(make_pair(qi, qj));
				}
			}
		}
		lvl++;
	}
	return lvl;
}
int DFS(int i, int j) {
	int dis = 0;
	if (DP[i][j] != -1)
		return DP[i][j];
	FO(e,0,8) {
		int ri = i + di[e], rj = j + dj[e];
		if (ri < n && ri >= 0 && rj < m && rj >= 0
				&& src[ri][rj] == src[i][j] + 1)
			dis = max(dis, DFS(ri, rj) + 1);
	}
	return DP[i][j] = dis;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	//freopen("o.txt", "wt", stdout);
#endif
	int co = 1;
	while (scanf("%d%d", &n, &m) && n && m) {
		memset(DP, -1, sizeof(DP));
		FO(e,0,n)
			scanf("%s", src[e]);
		int mx = 0;
		bool f = false;
		FO(i,0,n) {
			FO(e,0,m) {
				if (src[i][e] == 'A') {
					mx = max(mx, DFS(i, e));
					f = true;
				}
			}
		}
		if (f)
			printf("Case %d: %d\n", co++, mx + 1);
		else
			printf("Case %d: %d\n", co++, mx);
	}
	return 0;
}
// @Copy Right To Ahmed Nasser
