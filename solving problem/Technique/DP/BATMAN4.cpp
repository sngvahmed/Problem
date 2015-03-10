//Feb 28, 2014 :: BATMAN4.cpp
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
int di[] = { 0, 0, 1, -1 }, dj[] = { 1, -1, 0, 0 };
int n = 0, tim = 0, len, co;
bool vis[22][22];
int arr[106][106];
int dp[106][106];
bool validate(int i, int j) {
	return (i >= 0 && j >= 0 && i < n && j < n) ? 1 : 0;
}
int DP(int i, int j, int jump, bool check) {
	if (jump > len)
		return 1 << 30;
	if (i == n - 1 && j == n - 1) {
		if (!check)
			return 1 << 30;
		else
			return 0;
	}
	if (dp[i][j] != -1)
		return dp[i][j];
	int &ret = dp[i][j] = 1 << 30;
	if (validate(i + 1, j)) {
		int sum = abs(arr[i][j] - arr[i + 1][j]);
		ret = min(DP(i + 1, j, abs(sum), (sum == len) ? 1 : check) + abs(sum),
				ret);
	}
	if (validate(i, j + 1)) {
		int sum = abs(arr[i][j] - arr[i][1 + j]);
		ret = min(DP(i, j + 1, abs(sum), (sum == len) ? 1 : check) + abs(sum),
				ret);
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
		scanf("%d%d", &n, &co);
		FO (i,0,n)
			FO (r,0,n)
				scanf("%d", &arr[i][r]);
		int le = 1 << 30, sm = 1 << 30;
		FO(i,0,105) {
			MMS(dp, -1);
			len = i;
			int tmp = DP(0, 0, arr[0][0], arr[0][0] == i);
			if (tmp + arr[0][0] <= co && tmp + arr[0][0] < sm
					&& tmp != 1 << 30) {
				le = len, sm = tmp + arr[0][0];
				break;
			}
		}
		if (le == 1 << 30)
			cout << "NO" << endl;
		else
			cout << "YES : " << le << " " << co - sm << endl;
	}
	return 0;
}
// COPY@SNGV :: Feb 28, 2014 :: sngv

