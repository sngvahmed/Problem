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
int n, m, co = 0;
bool vis[22][22][1 << 11];
char arr[22][22];
map<pair<int, int>, int> nm;
bool validate(int i, int j) {
	return (i < 0 || i >= n || j < 0 || j >= m || arr[i][j] == 'x') ? 0 : 1;
}
class status {
public:
	int x, y, msk, num;
	status(int i, int j, int ms) {
		x = i, y = j, msk = ms;
	}
};
int BFS(int i, int j) {
	queue<status> que;
	status st(i, j, 0);
	que.push(st);
	int lvl = 0, msk;
	while (!que.empty()) {
		int sz = que.size();
		while (sz--) {
			st = que.front();
			que.pop();
			if (((1 << co) - 1) == st.msk)
				return lvl;
			for (int q = 0; q < 4; q++) {
				i = st.x + di[q], j = st.y + dj[q], msk = st.msk;
				if (validate(i, j) && vis[i][j][msk] == 0) {
					if (arr[i][j] == '*')
						msk |= (1 << nm[make_pair(i, j)]);
					que.push(status(i, j, msk));
					vis[i][j][msk] = 1;
				}
			}
		}
		lvl++;
	}
	return -1;
}
int BFSW(int i, int j) {
	queue<status> que;
	status st(i, j, 0);
	que.push(st);
	int lvl = 0, msk;
	while (!que.empty()) {
		int sz = que.size();
		while (sz--) {
			st = que.front();
			que.pop();
			if (co == st.msk)
				return lvl;
			for (int q = 0; q < 4; q++) {
				i = st.x + di[q], j = st.y + dj[q], msk = st.msk;
				if (validate(i, j) && vis[i][j][msk] == 0) {
					if (arr[i][j] == '*')
						msk |= (1 << nm[make_pair(i, j)]);
					que.push(status(i, j, msk));
					vis[i][j][msk] = 1;
				}
			}
		}
		lvl++;
	}
	return -1;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	freopen("o.txt", "wt", stdout);
#endif
	while (scanf("%d%d", &m, &n) && n != 0 && m != 0) {
		memset(vis, 0, sizeof vis);
		int ini, ine;
		co = ini = ine = 0;
		FO(i,0,n)
			FO(e,0,m) {
				cin >> arr[i][e];
				if (arr[i][e] == 'o')
					ini = i, ine = e;
				if (arr[i][e] == '*')
					nm[make_pair(i, e)] = co++;
			}
		cout << BFS(ini, ine) << endl;
	}
	return 0;
}
// @Copy Right To Ahmed Nasser
