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
typedef pair<int, int> pr;
int ret[189][189], n, m;
string arr[189];
bool vis[189][189];
int di[] = { 0, 0, 1, -1 };
int dj[] = { 1, -1, 0, 0 };
bool validate(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == 0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	int co = 0;
	scanf("%d", &co);
	while (co--) {
		scanf("%d%d", &n, &m);
		MMS(vis, 0), MMS(ret,0);
		queue<pr> que;
		FO(i,0,n) {
			FO (j,0,m) {
				cin >> arr[i][j];
				if (arr[i][j] == '1')
					que.push(mp(i, j)), vis[i][j] = 1, ret[i][j] = 1;
			}
		}
		int lvl = 0;
		while (!que.empty()) {
			int sz = que.size();
			while (sz--) {
				pr tmp = que.front();
				que.pop();
				ret[tmp.F][tmp.S] = lvl;
				FO(r,0,4) {
					int DI = tmp.F + di[r], DJ = dj[r] + tmp.S;
					if (validate(DI, DJ) && !vis[DI][DJ])
						que.push(mp(DI, DJ)), vis[DI][DJ] = 1;
				}
			}
			lvl++;

		}
		FO(i,0,n) {
			FO(j,0,m)
				cout << ret[i][j] << " ";
			cout << endl;
		}

	}
}

// @Copy Right To Ahmed Nasser
