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
	int n;
	SF(n);
	int rem = (n / 2) + 1;
	int t = rem - 1, tot = 1;
	int tx = 0, ty = n - 2;
	bool f1 = 0, f2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < t; j++) {
			cout << "*";
		}
		if (f1 == 0) {
			for (int j = 0; j <= tx; j++) {
				cout << "D";
			}
		} else if (f2 == 0) {
			for (int j = 0; j < ty; j++) {
				cout << "D";
			}
		}
		for (int j = 0; j < t; j++) {
			cout << "*";
		}

		(f1 == 1) ? ty -= 2 : f1;
		(tx == n - 1) ? f1 = 1 : tx += 2;
		(f1) ? t += 1 : t -= 1;
		cout << endl;
	}
	return 0;
}
