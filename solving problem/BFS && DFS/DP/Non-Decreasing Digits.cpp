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
long long int DP[65][10];
long long int dp(int i, string str, int j) {
	if (i == m && SZ(str) == m)
		return 1;
	if (i == m)
		return 0;
	if (SZ(str) > 0 && DP[i][j] != -1)
		return DP[i][j];
	long long int &ret = DP[i][j] = 0;
	FO(r,0,10) {
		if (i == 0 || char(r + '0') >= str[i - 1])
			ret += dp(i + 1, str + char(r + '0'), r);
	}
	return ret;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	int to;
	scanf("%d", &to);
	while (to--) {
		cin >> n >> m;
		MMS(DP, -1);
		cout << n << " " << dp(0, "", 0) << endl;
	}
	return 0;
}
// COPY@SNGV
