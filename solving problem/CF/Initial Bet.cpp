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
//	freopen("test.in", "rt", stdin);
	int arr[5], tot = 0;

	for (int i = 0; i < 5; i++) {
		SF(arr[i]), tot += arr[i];
	}
	if (tot % 5 != 0 || tot == 0) {
		cout << -1 << endl;
	} else {
		cout << tot / 5 << endl;
	}
	return 0;
}
