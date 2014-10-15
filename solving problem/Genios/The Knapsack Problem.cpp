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
int n = 0, m = 0, co = 0;
vector<pair<int, int> > var;
int dp[5000][5000];
int DP(int i, int sum, int len) {
	if (i == SZ(var))
		return 0;
	if (dp[i][len] != -1)
		return dp[i][len];
	int &ret = dp[i][len] = 0;
	ret = max(ret, DP(i + 1, sum, len));
	if (len >= var[i].F) {
		ret = max(ret, DP(i + 1, sum + var[i].S, len - var[i].F) + var[i].S);
	}
	return ret;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	scanf("%d%d", &n, &m);
	FO(i,0,m) {
		int tm1, tm2;
		scanf("%d%d", &tm1, &tm2);
		var.pb(mp(tm1, tm2));
	}
	MMS(dp, -1);
	cout << DP(0, 0, n);
	return 0;
}
// COPY@SNGV
