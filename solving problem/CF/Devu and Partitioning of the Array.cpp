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
	freopen("test.in", "rt", stdin);

	/*
	 5 5 3
	 7 14 2 9 5

	 var even :: 14  2
	 var odd  :: 7   9  5

	 14
	 2
	 7 5

	 */

	int n, k, p;
	vector<int> odd, even;
	scanf("%d%d%d", &n, &k, &p);
	int numberOfOdd = k - p;

	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		(tmp % 2 != 0) ? odd.pb(tmp) : even.pb(tmp);
	}
	vector<vector<int> > var(10000);

	if ((SZ(even) + (SZ(odd) / 2)) < p) {
		cout << "NO" << endl;
		return 0;
	}

	int indxOdd = 0, i;
	for (i = 0; i < p; i++) {
		if (i >= SZ(even) && indxOdd >= SZ(odd)) {
			cout << "NO" << endl;
			return 0;
		}

		if (p > 0 && i == 0 && SZ(even) > p)
			while (SZ(even) > p)
				var[0].pb(even[0]), even.erase(even.begin());

		else if (i < SZ(even))
			var[i].pb(even[i]);
		else if (SZ(odd))
			var[i].pb(odd[indxOdd]), var[i].pb(odd[indxOdd + 1]), indxOdd += 2;

	}
	bool firstTime = 1;

	for (; i < k; i++) {

		if (indxOdd >= SZ(odd)) {
			cout << "NO" << endl;
			return 0;
		}

		if (firstTime && SZ(odd) > numberOfOdd)
			while (SZ(odd) >= numberOfOdd)
				var[i].pb(odd[indxOdd]), odd.erase(odd.begin() + indxOdd);
		else {
			var[i].pb(odd[indxOdd]);
			indxOdd++;
		}

	}
	i = 0;
	cout << "YES" << endl;
	while (SZ(var[i])) {
		cout << SZ(var[i]) << " ";
		for (int j = 0; j < SZ(var[i]); j++)
			if (j == SZ(var[i]) - 1)
				cout << var[i][j];
			else
				cout << var[i][j] << " ";
		cout << endl;
		i++;
	}
	return 0;
}
