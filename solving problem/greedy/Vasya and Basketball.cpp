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
typedef unsigned long long int ull;

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif

	int n, tmp;
	cin >> n;
	vector<ull> b, a;
	while (n--)
		cin >> tmp, a.pb(tmp);
	cin >> n;
	while (n--)
		cin >> tmp, b.pb(tmp);
	sort(all(a)), sort(all(b));
	int mx1, mx2;
	mx1 = SZ(a) * 2, mx2 = SZ(b) * 2;
	for (int i = 0; i < SZ(a); i++) {
		int tot1 = (i * 2) + ((SZ(a) - i) * 3);
		int indx = upper_bound(all(b), a[i] - 1) - b.begin();
		int tot2 = (indx * 2) + ((SZ(b) - indx) * 3);
		if ((tot1 - tot2) > (mx1 - mx2)) {
			mx1 = tot1, mx2 = tot2;
		} else if ((tot1 - tot2) == (mx1 - mx2) && tot1 > mx1)
			mx1 = tot1, mx2 = tot2;
	}
	cout << mx1 << ":" << mx2 << endl;
	return 0;
}
