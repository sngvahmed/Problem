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

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	int i = 0, n;
	cin >> n;
	vector<pair<int, int> > var(n);
	int mnx = 1000000001, mny = 1000000001, mxx = -1000000001,
			mxy = -1000000001;
	while (n--) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		mnx = min(mnx, tmp1), mny = min(mny, tmp2);
		mxx = max(mxx, tmp1), mxy = max(mxy, tmp2);
	}
	unsigned long long tot = max(abs(mxx - mnx), abs(mxy - mny));

	cout << ((unsigned long long) tot * tot) << endl;
	return 0;
}
