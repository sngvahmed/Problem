// Mar 15, 2014 Searching Problem.cpp
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
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MMS(x, v) memset(x, v, sizeof(x))
#define SQ(x) (x) * (x)

typedef pair<int, int> pr;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<string> vs;
typedef vector<int> vi;
int di[] = { 0, 0, 1, -1, 1, -1, 1, -1 }, dj[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
int vis[51][51];
char arr[51][51];
int n = 0, m = 0, co = 0;
string str;
bool validate(int i, int j) {
	return (i >= 0 && j >= 0 && i < n && j < m && arr[i][j] != '1') ? 1 : 0;
}
class TR {
public:
	int x, y, z;
	TR(int x, int y, int z) {
		this->x = x, this->y = y, this->z = z;
	}
};
int BFS(int i, int j) {
	deque<TR> que;
	que.push_front(TR(i, j, 0));
	while (!que.empty()) {
		int sz = que.size();
		while (sz--) {
			TR tmp = que.front();
			que.pop_front();
			FO(r,0,4) {
				int DI = tmp.x + di[r], DJ = tmp.y + dj[r];
				if (vis[DI][DJ] == 0 && validate(DI, DJ)) {
					if (arr[DI][DJ] == '$')
						return tmp.z;
					vis[DI][DJ] = 1;
					if (arr[DI][DJ] == '0')
						que.pf(TR(DI, DJ, tmp.z));
					else
						que.pb(TR(DI, DJ, tmp.z + 1));
				}
			}
		}
	}
	return 0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	while (scanf("%d%d", &n, &m) && n && m) {
		MMS(vis, 0);
		int ii, jj;
		FO(i,0,n) {
			FO(j,0,m) {
				cin >> arr[i][j];
				if (arr[i][j] == 'S')
					ii = i, jj = j;
			}
		}
		cout << BFS(ii, jj) << endl;
	}
}
//@CPY::SNGV
