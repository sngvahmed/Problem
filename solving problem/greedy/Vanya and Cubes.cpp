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
typedef long long ll;
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	ll n = 0, tmp, i = 1;
	cin >> tmp;
	while (tmp > 0) {
		n += i, i++, tmp -= n;
	}
	i--;
	if (tmp < 0)
		i--;
	cout << i << endl;
	return 0;
}
