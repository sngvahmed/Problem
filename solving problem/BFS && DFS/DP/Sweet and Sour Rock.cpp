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
int dp[250][220], n;
string str;
int DP(int i, int n0, int n1) {
	if (i == SZ(str)) {
		if (n1 > n0) {
			return 0;
		}
		return -30000;
	}
	if (dp[i][n1 + n0] != -1)
		return dp[i][n1 + n0];
	int &r = dp[i][n1 + n0] = -100000;
	if (n1 > n0)
		r = max(r, DP(i, 0, 0));
	if (!n1 && !n0) {
		r = max(r, DP(i + 1, 0, 0));
		r = max(r, 0);
	}
	r = max(r, DP(i + 1, n0 + (str[i] == '0'), n1 + (str[i] == '1')) + 1);
	return r;
}
int main() {
	int to;
	scanf("%d", &to);
	while (to--) {
		scanf("%d", &n);
		MMS(dp, -1);
		cin >> str;
		cout << DP(0, 0, 0) << endl;
	}
	return 0;
}
// COPY@SNGV

