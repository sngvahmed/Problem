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
double max(double d1, double d2) {
	if (d1 > d2)
		return d1;
	return d2;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	int n, m;
	SF(n), SF(m);
	int arr[n];
	for (int i = 0; i <= n; i++)
		SF(arr[i]);
	double tot = -1;
	sort(arr, arr + n);
	for (int i = 1; i < n; i++) {
		tot = max(tot, (arr[i] - arr[i - 1]) / double(2));
	}
	if (arr[0] != 0)
		tot = max(tot, arr[0]);
	if (arr[n - 1] != m)
		tot = max(tot, m - arr[n - 1]);

	cout << setprecision(9) << fixed << tot << endl;
	return 0;
}
