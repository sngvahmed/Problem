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

	int n, m;
	cin >> n >> m;
	long long arr[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	long long tot = 0;

	for (int i = 0; i < n; i++) {
		tot += (arr[i] * (max(1, m--)));
	}

	cout << tot << endl;

	return 0;
}
