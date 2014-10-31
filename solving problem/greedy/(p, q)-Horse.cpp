#include "bits/stdc++.h"
#include <functional>

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
typedef pair<int, vi> pi;
typedef pair<int, int> vp;
typedef pair<int, pair<int, int> > Hamada;
map<int, vi> var;
int m, n, p, q, x1, x2, y2, yy1;
bool vis[100][100];
int di[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dj[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
bool validate(int x, int y) {
	return (x < n && y < m) ? 1 : 0;
}
//int BFS() {
//	queue<pair<int, int> > que;
//	que.push(mp(x1, yy1));
//	int count = 0;
//	while (!que.empty()) {
//		int sz = que.size();
//		count++;
//		while (sz--) {
//			pair<int, int> tmp = que.front();
//			cout << tmp.F << " " << tmp.S << endl;
//			que.pop();
//			if (tmp.F == x2 && tmp.S == y2)
//				return count;
//			FO(i , 0 , 8) {
//				int x = tmp.F + di[i], y = tmp.S + dj[i];
//				if (validate(x, y) && vis[x][y] == 0)
//					que.push(mp(x, y)), vis[x][y] = 1;
//				x = tmp.F + dj[i], y = tmp.S + di[i];
//				if (validate(x, y) && vis[x][y] == 0)
//					que.push(mp(x, y)), vis[x][y] = 1;
//			}
//		}
//	}
//	return -1;
//}
int main() {
	cin >> m >> n >> p >> q >> x1 >> yy1 >> x2 >> y2;
	FO(i , 0 , 8) {
		di[i] = di[i] * p;
		dj[i] = dj[i] * q;
	}
	MMS(vis, 0);
//	cout << BFS() << endl;
	return 0;
}
