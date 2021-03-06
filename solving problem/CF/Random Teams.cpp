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

int main() {

	unsigned long long n, m;
	cin >> n >> m;
	if (n == m) {
		unsigned long long out = n - (m - 1);
		cout << 0 << " " << (out * (out - 1)) / 2 << endl;
		return 0;
	}
	unsigned long long rem = n % m;
	unsigned long long tot = n / m;
	unsigned long long ret = 0;
	for (unsigned long long i = 0; i < rem; i++) {
		ret += ((tot + 1) * tot) / 2;
	}
	for (unsigned long long i = 0; i < m - rem; i++) {
		ret += ((tot - 1) * tot) / 2;
	}
	unsigned long long out = n - (m - 1);
	cout << ret << " " << (out * (out - 1)) / 2 << endl;

	return 0;
}
