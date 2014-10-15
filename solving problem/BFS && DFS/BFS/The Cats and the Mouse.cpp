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
string ret = "ABCDEF ";
int lvl = -1;
int n, m;
bool validateSucces(int x, int y) {
	return (x == 0 || y == 0 || x == n + 1 || y == m + 1) ? true : false;
}
bool validate(int x, int y) {
	return (x > 0 && y > 0 && y <= m && x <= n) ? true : false;
}
class pr {
public:
	char kind;
	int x, y;
	pr(int x, int y, char kind) {
		this->x = x, this->y = y, this->kind = kind;
	}
};
int main() {
#ifndef ONLINE_JUDGE
//	freopen("test.in", "rt", stdin);
//	freopen("o.txt", "wt", stdout);
#endif
	scanf("%d%d", &n, &m);
	int co;
	scanf("%d", &co);
	while (co--) {
		bool vis[n + 2][m + 2][2];
		memset(vis, 0, sizeof vis);
		queue<pr> num;
		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				int tmp1, tmp2;
				scanf("%d%d", &tmp1, &tmp2);
				num.push(pr(tmp1, tmp2, 'R'));
				vis[tmp1][tmp2][1] = 1;
			} else {
				int tmp1, tmp2;
				scanf("%d%d", &tmp1, &tmp2);
				num.push(pr(tmp1, tmp2, 'C'));
				vis[tmp1][tmp2][0] = 1;
			}
		}
		bool rat = 1;
		while (!num.empty()) {
			int sz = num.size();
			while (sz--) {
				pr mv = num.front();
//				cout << mv.x << " " << mv.y << " " << mv.kind << " "
//						<< vis[mv.x][mv.y][(mv.kind == 'R') ? 1 : 0] << endl;
				num.pop();
				if (validateSucces(mv.x, mv.y) && mv.kind == 'R') {
					cout << "YES";
					rat = 0;
					break;
				}
				if ((vis[mv.x][mv.y][0] == 0 && mv.kind == 'R')
						|| (mv.kind == 'C' && validate(mv.x, mv.y)))
					for (int i = 0; i < 4; i++) {
						int tm1 = mv.x + di[i], tm2 = mv.y + dj[i];
						if (tm1 >= 0 && tm2 >= 0
								&& vis[tm1][tm2][(mv.kind == 'R') ? 1 : 0]
										== 0) {
							num.push(pr(tm1, tm2, mv.kind));
							vis[tm1][tm2][(mv.kind == 'R') ? 1 : 0] = 1;
						}
					}
			}
			if (!rat)
				break;
		}
		if (rat)
			cout << "NO";
		cout << endl;
	}
	return 0;
}
/*5 3
 3
 2 2 1 1 3 3
 2 3 1 3 5 2
 3 2 1 2 4 3*/
