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

typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<string> vs;
typedef vector<int> vi;
int di[] = { 0, 1, 1, 1 }, dj[] = { 1, 0, 1, -1 };
int n = 0, m = 3, co = 0, disx, disj;
vector<vi> var;
int dp[100001][3];
bool validate(int i, int j) {
	return (i >= 0 && j >= 0 && i < n && j < m) ? 1 : 0;
}
int DP(int i, int j, pi prev) {
	if (i == disx && disj == j)
		return 0;
	if (dp[i][j] != 0)
		return dp[i][j];
	int &ret = dp[i][j] = 1 << 30;
	FO(r,0,4) {
		int DI = i + di[r], DJ = j + dj[r];
		if (validate(DI, DJ) && mp(DI, DJ) != prev)
			ret = min(ret, DP(DI, DJ, mp(i, j)) + var[DI][DJ]);
	}
	return ret;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
//	freopen("o.txt", "wt", stdout);
#endif
	int to = 0;
	while (scanf("%d", &n) && n) {
		MMS(dp, 0);
		var.clear();
		FO(i,0,n) {
			int tm1, tm2, tm3;
			vi tmp;
			scanf("%d%d%d", &tm1, &tm2, &tm3);
			tmp.pb(tm1), tmp.pb(tm2), tmp.pb(tm3);
			var.pb(tmp);
		}
		disx = n - 1, disj = 1;
		cout << ++to << ". " << DP(0, 1, mp(-1, -1)) + var[0][1] << endl;
	}
	return 0;
}
// COPY@SNGV
