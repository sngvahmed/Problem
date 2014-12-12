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
#define SF(x) scanf("%d" , %x)

int main() {

#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	int n, m;
	while (cin >> n >> m) {
		int arr[m + 1];
		bool out = true;
		for (int i = 0; i < m; i++)
			cin >> arr[i];
		arr[m] = arr[0] + n;
		for (int i = arr[0]; i < arr[1]; i++) {
			bool ch = true;
			int tmp = i;
			for (int j = 1; j <= m; j++) {
				if (tmp < arr[j] && arr[j] <= tmp + (n / m)) {
					tmp += (n / m);
				} else {
					ch = false;
				}
			}
			if (ch) {
				cout << "S" << endl;
				out = false;
				break;
			}
		}
		if (out)
			cout << "N" << endl;
	}

	return 0;
}
