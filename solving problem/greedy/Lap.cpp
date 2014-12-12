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
	int x, y;
	while (cin >> x >> y) {
		int diff = y - x;
		if (y % diff == 0) {
			cout << y / diff << endl;
		} else
			cout << 1 + (y / diff) << endl;
	}
	return 0;
}
