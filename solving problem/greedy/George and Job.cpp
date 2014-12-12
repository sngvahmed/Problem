#include "bits/stdc++.h"
#include <functional>
#include <ext/numeric>
using namespace std;

#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MMS(x, v) memset(x, v, sizeof(x))
#define SF(x) scanf("%d" , &x)
int sz, m, n;
vector<int> arr(5001);
long long dp[5001][5001];
long long tt[5001];
long long REC(int indx, int k) {
	if (k == 0)
		return 0;

	if (indx >= n)
		return -1000000000;

	if (dp[indx][k] != -1)
		return dp[indx][k];

	long long ret = -1000000000;
	ret = max(ret, REC(indx + 1, k));
	ret = max(ret, REC(indx + m, k - 1) + tt[indx]);
	return dp[indx][k] = ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int k;
	SF(n), SF(m), SF(k);
	int i = 0, s = 0;
	long long sum = 0;
	while (i != n) {
		SF(arr[i]), sum += arr[i];
		if (i >= (m - 1))
			tt[s] = sum, sum -= arr[s], s++;
		i++;
	}
	MMS(dp, -1);
	printf("%lld", REC(0, k));
	return 0;
}
