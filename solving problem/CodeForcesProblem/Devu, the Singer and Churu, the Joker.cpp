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
	int n, d;
	scanf("%d%d", &n, &d);
	int arr[n], tot = 0;

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]), tot += arr[i];
	if ((tot + ((n - 1) * 10)) > d) {
		cout << -1 << endl;
		return 0;
	}

	cout << (d - tot) / 5 << endl;
}
