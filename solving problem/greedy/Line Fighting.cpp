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
#define SF(x) scanf("%d" , %x)

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	int n;
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		int rem = x % y;
		unsigned long long tot = 0;
		rem = (x % y);
		for (int i = 1; i < y; i++) {
			if (rem) {
				rem--;
				int rs = (y - i) - rem;
				int mul = (x / y) + 1;
				int t = rs * (mul - 1);
				t += rem * (mul);
				t = t * (mul);
				tot += t;
			} else {
				int mul = (x / y);
				tot += (mul * (((y - i)) * (x / y)));
			}
		}
		cout << tot << endl;
	}
	return 0;

}
