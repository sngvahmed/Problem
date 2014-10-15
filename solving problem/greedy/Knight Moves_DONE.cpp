#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <list>
#include <set>
#include <climits>
#include <map>
#include <stack>
#include <queue>
#include <complex>
#include <cmath>
#include <sstream>
#include <deque>
#include <utility>
#include <bitset>
#include <ext/hash_set>
#include <ext/hash_map>

using namespace std;
using namespace __gnu_cxx;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define oo 2e9
#define MAX 2001
#define sz(v) (int)v.size()
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define iter(it,s) for(it=s.begin();it!=s.end();it++)
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define mem(s,v) memset(s,v,sizeof(s))

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

int dx[] = { -1, -1, -2, -2, 1, 1, 2, 2 };
int dy[] = { 2, -2, 1, -1, 2, -2, 1, -1 };

int vis[9][9];

/*
 e2 e4
 a1 b2
 b2 c3
 a1 h8
 */

char in1[3], in2[3];
int sx, sy, ex, ey;

inline bool bound(int x, int y) {
	return (x >= 0 && x < 8 && y >= 0 && y < 8 && !vis[x][y]);
}

int bfs() {
	queue<pi> q;
	q.push(mp(sx, sy));
	vis[sx][sy] = 1;
	int res = 0;
	while (!q.empty()) {
		int si = sz(q);
		while (si--) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			if (x == ex && y == ey)
				return res;
			FOR (i , 0 , 8) {
				int xx = dx[i] + x, yy = dy[i] + y;
				if (bound(xx, yy)) {
					q.push(mp(xx, yy));
					vis[xx][yy] = 1;
				}
			}
		}
		res++;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	//  freopen("o.txt", "wt", stdout);
#endif
	while (scanf("%s", in1) != -1) {
		sx = in1[0] - 'a', sy = in1[1] - '0' - 1;
		scanf("%s", in2);
		ex = in2[0] - 'a', ey = in2[1] - '0' - 1;
		mem (vis, 0);
		printf("To get from %s to %s takes %d knight moves.\n", in1, in2, bfs());
	}
	return 0;
}
