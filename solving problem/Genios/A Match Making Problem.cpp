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
bool vis[189][189];
int lvl = -1;
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	freopen("o.txt", "wt", stdout);
#endif
	int n, m, tmp, co = 1;
	while (scanf("%d%d", &n, &m) && n != 0 && m != 0) {
		vector<int> x, y;
		FO(i,0,n) {
			scanf("%d", &tmp);
			x.push_back(tmp);
		}
		FO(i,0,m) {
			scanf("%d", &tmp);
			y.push_back(tmp);
		}
		if (n <= m) {
			cout << "Case " << co++ << ": " << 0 << endl;
		} else {
			sort(x.rbegin(), x.rend()), sort(y.rbegin(), y.rend());
			int mn = 1 << 30, i;
			for (i = 0; i < SZ(x); i++) {
				if (mn > abs(y[0] - x[i]))
					mn = min(mn, y[0] - x[i]);
				else
					break;
			}
			cout << "Case " << co++ << ": " << x.size() - y.size() << " ";
			int yong = 1 << 30;
			FO (j,0,i+1)
				yong = min(yong, x[j]);
			FO(j,i+SZ(y),SZ(x))
				yong = min(yong, x[j]);
			cout << yong << endl;
		}
	}
	return 0;
}
