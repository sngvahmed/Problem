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
int n, tmp1, tmp2;
string str1, str2;
vector<pair<int, int> > var;
double dp[100001];
double DP(int i) {
	if (i == SZ(var))
		return 0;
	if (dp[i] != -1.0)
		return dp[i];
	double &ret = dp[i] = 0, tot = var[i].S * var[i].F;
	ret = max(DP(i + 1), (tot + (100 - var[i].F) * DP(i + 1)) / 100);
	return ret;
}
int main() {
	while (scanf("%d", &n) && n) {
		var.clear();
		FO(i,0,n)
			scanf("%d%d", &tmp1, &tmp2), var.pb(mp(tmp1, tmp2)), dp[i] = -1.0;
		printf("%.2lf\n", DP(0));
	}
	return 0;
}

