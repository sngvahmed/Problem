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
typedef long long int lli;

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif

	int n;
	cin >> n;
	vector<lli> x1, x2;
	lli sum1, sum2, tmp;
	sum1 = sum2 = 0;
	while (n--) {

		cin >> tmp;
		if (tmp > 0) {
			x1.pb(tmp);
			sum1 += tmp;
		} else {
			x2.pb(tmp * -1);
			sum2 += (-1) * tmp;
		}
	}
	if (sum1 > sum2) {
		cout << "first" << endl;
		return 0;
	} else if (sum1 < sum2) {
		cout << "second" << endl;
		return 0;
	} else {
		for (int i = 0; i < min(SZ(x1), SZ(x2)); i++) {
			if (x1[i] > x2[i]) {
				cout << "first" << endl;
				return 0;
			} else if (x1[i] < x2[i]) {
				cout << "second" << endl;
				return 0;
			}
		}
	}
	if (tmp > 0)
		cout << "first" << endl;
	else
		cout << "second" << endl;
	return 0;
}
