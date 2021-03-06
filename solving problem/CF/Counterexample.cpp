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
	long long st, end;
	cin >> st >> end;
	for (long long i = st; i <= end; i++) {
		for (long long j = i + 1; j <= end; j++) {
			if (__gcd(i, j) != 1)
				continue;
			for (long long k = j + 1; k <= end; k++) {
				if (__gcd(j, k) == 1 && __gcd(i, k) != 1) {
					cout << i << " " << j << " " << k << endl;
					return 0;
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
