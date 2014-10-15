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
int n, m;
int ret[189][189];
char sr[189][189];
bool vis[189][189];
int di[] = { 0, 0, 1, -1 };
int dj[] = { 1, -1, 0, 0 };
//********* MC BFS **************
void bfs() {
	int si, sj;
	memset(vis, 0, sizeof vis);
	queue<pair<int, int> > Q;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (sr[i][j] == '1') {
				Q.push(make_pair(i, j));
				ret[i][j] = 0;
				vis[i][j] = 1;
			}
	int sz, steps = 1;
	while (!Q.empty()) {
		sz = Q.size();
		while (sz--) {
			si = Q.front().first;
			sj = Q.front().second;
			Q.pop();
			for (int k = 0; k < 4; ++k) {
				int i = si + di[k];
				int j = sj + dj[k];
				if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j])
					continue;
				if (sr[i][j] == '0')
					ret[i][j] = steps;
				vis[i][j] = 1;
				Q.push(make_pair(i, j));
			}
		}
		steps++;
	}
}
//**********************************************
int BFS(int si, int sj) {
	memset(vis, 0, sizeof(vis));
	queue<pair<int, int> > Q;
	Q.push(make_pair(si, sj));
	int step = 0;
	if (sr[si][sj] == '1')
		return step;
	vis[si][sj] = 1;
	while (!Q.empty()) {
		int sz = Q.size();
		while (sz--) {
			si = Q.front().first;
			sj = Q.front().second;
			Q.pop();
			for (int i = 0; i < 4; i++) {
				int ri = si + di[i];
				int rj = sj + dj[i];
				if (ri >= n || ri < 0 || rj >= m || rj < 0 || vis[ri][rj] == 1)
					continue;
				if (sr[ri][rj] == '1')
					return step + 1;
				vis[ri][rj] = 1;
				Q.push(make_pair(ri, rj));
			}
		}
		step++;
	}
	return step;
}
void BFSI() {
	memset(vis, 0, sizeof(vis));
	queue<pair<int, int> > num;
	FO(i,0,n) {
		FO(e,0,m) {
			if (sr[i][e] == '1') {
				ret[i][e] = 0;
				vis[i][e] = 1;
				num.push(make_pair(i, e));
			}
		}
	}
	int step = 1;
	while (!num.empty()) {
		int sz = num.size();
		while (sz--) {
			int bi = num.front().first, bj = num.front().second;
			num.pop();
			FO(i,0,4) {
				int ri = bi + di[i], rj = bj + dj[i];
				if (ri >= n || ri < 0 || vis[ri][rj] || rj >= m || rj < 0)
					continue;
				if (sr[ri][rj] == '0')
					ret[ri][rj] = step;
				vis[ri][rj] = 1;
				num.push(make_pair(ri, rj));
			}
		}
		step++;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	//freopen("o.txt", "wt", stdout);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%s", sr[i]);
		}
		BFSI();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (j)
					putchar(' ');
				printf("%d", ret[i][j]);
			}
			putchar('\n');
		}
	}
}

// @Copy Right To Ahmed Nasser

