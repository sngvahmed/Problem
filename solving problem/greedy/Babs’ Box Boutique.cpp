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
int n, ret = 0;
vector<vector<int> > var;
void REC(int i, int r1, int r2, int cont) {

}
bool compare(const vi &p1, const vi &p2) {
	if (p1[0] >= p2[0] && p1[1] >= p2[1])
		return 1;
	return 0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	int to = 0;
	while (scanf("%d", &n) && n) {
		FO(i,0,n) {
			int tm1, tm2, tm3;
			scanf("%d%d%d", &tm1, &tm2, &tm3);
			vi tm;
			tm.pb(tm1), tm.pb(tm2), tm.pb(tm3);
			sort(rall(tm));
			var.pb(tm);
		}
		sort(var.rbegin(), var.rend(), compare);
		FO(i,0,SZ(var)) {
			cout << var[i][0] << " " << var[i][1] << " " << var[i][2] << endl;
		}
		REC(0, 1 << 30, 1 << 30, 0);
		cout << "Case " << ++to << ": " << ret << endl;
		ret = 0, var.clear();
	}
	return 0;
}

