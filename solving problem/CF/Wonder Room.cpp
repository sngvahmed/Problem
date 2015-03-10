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

typedef unsigned long long ull;

int main() {
//	freopen("test.in", "rt", stdin);
	ull n, a, b;
	cin >> n >> a >> b;
	ull tot = 1000000000000000009, width, lenth;
	n *= 6;

	for (ull i = a; i <= max(a, (ull) sqrt(n)); i++) {
		ull j = max(b, n / i + (n % i != 0));
		if (i * j < tot)
			tot = i * j, width = i, lenth = j;
	}
	for (ull j = b; j <= max(b, (ull) sqrt(n)); j++) {
		ull i = max(a, n / j + (n % j != 0));
		if (i * j < tot)
			tot = i * j, width = i, lenth = j;
	}
	cout << tot << endl << width << " " << lenth << endl;
	return 0;
}
