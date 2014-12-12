#include "bits/stdc++.h"
#include <functional>
#include <ext/numeric>
using namespace std;

#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MMS(x, v) memset(x, v, sizeof(x))
#define SF(x) scanf("%d" , %x)
int di[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dj[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
int n = 8, m = 8, vis[8][8], rx, ry, nonx, nony;
bool validate(int i, int j) {
	return (i < 0 || i >= n || j < 0 || j >= m) ? 0 : 1;
}

int BFS(int x, int y) {
	MMS(vis, 0);
	queue<pair<int, int> > q;
	q.push(mp(x, y));
	int cur = 0;
	while (q.size()) {
		int sz = q.size();
		while (sz--) {
			pair<int, int> tmp = q.front();
			q.pop();
			if (tmp.F == rx && tmp.S == ry)
				return cur;
			for (int i = 0; i < 8; i++) {
				x = di[i] + tmp.F, y = dj[i] + tmp.S;
				if (x == nonx && y == nony)
					continue;
				if (validate(x, y) && vis[x][y] == 0) {
					vis[x][y] = 1;
					q.push(mp(x, y));
				}
			}
		}
		cur++;
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	int stx, sty, lop = 1;
	while (cin >> stx >> sty >> rx >> ry >> nonx >> nony) {
		nonx--, nony--, stx--, sty--, rx--, ry--;
		printf("Case %d: %d\n", lop++, BFS(stx, sty));
	}
	return 0;
}
