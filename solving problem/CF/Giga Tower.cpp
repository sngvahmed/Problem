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

bool no8(long long x) {
	while (x) {
		int num = x % 10;
		if (num == 8)
			return 1;
		x = x / 10;
	}
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	long long x, y;
	cin >> x;
	y = x;
	do {
		x++;
	} while (!no8(abs(x)));
	cout << x - y << endl;
	return 0;
}
