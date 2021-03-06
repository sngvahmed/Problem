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
//  freopen("test.in", "rt", stdin);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(rall(arr));
	int i = n, count = 1;
	int tot = arr[0];
	while (tot > 0 && i > 0) {
		i--;
//		cout << i << " " << tot << " " << arr[i] << " " << count << endl;
		if (tot > arr[i]) {
			tot -= arr[i], count++;
		} else if (tot == arr[i]) {
			cout << min(n, count + 1) << endl;
			return 0;
		}
	}
	cout << min(n, count) << endl;
	return 0;
}
