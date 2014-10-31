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
int n = 0, m = 0, co = 0, dp[101][102][102], arr[101];
int DP(int bat, int cat, int ind) {
	if (ind == n)
		return 0;
	if (dp[ind][bat][cat] != -1)
		return dp[ind][bat][cat];
	int &ret = dp[ind][bat][cat] = 0;
	ret = max(ret, DP(bat, cat, ind + 1));
	if (arr[ind] > bat)
		ret = max(ret, DP(arr[ind], cat, ind + 1) + 1);
	if (arr[ind] < cat)
		ret = max(ret, DP(bat, arr[ind], ind + 1) + 1);
	return ret;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	int to;
	scanf("%d", &to);
	while (to--) {
		MMS(dp, -1);
		scanf("%d", &n);
		FO(i,0,n)
			scanf("%d", &arr[i]);
		cout << DP(0, 101, 0) << endl;
	}
	return 0;
}
// COPY@SNGV

