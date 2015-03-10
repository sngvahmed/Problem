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
int di[] = { -2, -2, -1, 1, 2, 2, -1, 1 };
int dj[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
bool vis[8][8];
int BFS(int sx, int sy, int dx, int dy) {
	memset(vis, 0, sizeof(vis));
	if (sx == dx && sy == dy)
		return 0;
	int lvl = 1;
	queue<pair<int, int> > Q;
	Q.push(make_pair(sx, sy));
	vis[sx][sy] = 1;
	while (!Q.empty()) {
		int sz = Q.size();
		while (sz--) {
			int ri = Q.front().first;
			int rj = Q.front().second;
			Q.pop();
			FO(e,0,8) {
				int i = ri + di[e];
				int j = rj + dj[e];
				if (i >= 8 || i < 0 || j >= 8 || j < 0 || vis[i][j])
					continue;
				if (i == dx && j == dy)
					return lvl;
				vis[i][j] = 1;
				Q.push(make_pair(i, j));
			}
		}
		lvl++;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	//freopen("o.txt", "wt", stdout);
#endif
	char x1[3], x2[3];
	while (scanf("%s %s", x1, x2) != EOF) {
		string tmp1 = x1, tmp2 = x2;
		x1[0] = x1[0] % 'a' + '0' + 1;
		x2[0] = x2[0] % 'a' + '0' + 1;
		cout << "To get from " << tmp1 << " to " << tmp2 << " takes "
				<< BFS((x1[0] - '0') - 1, (x1[1] - '0') - 1, (x2[0] - '0') - 1,
						(x2[1] - '0') - 1) << " knight moves." << endl;
	}
	return 0;
}
// @Copy Right To Ahmed Nasser
