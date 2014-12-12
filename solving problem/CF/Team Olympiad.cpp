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
	int n, i = 0;
	SF(n);
	vector<int> var(n), tot;
	while (n--)
		SF(var[i]), i++;
	vector<vector<int> > res;
	do {
		int s = 4;
		tot.clear();
		while (s--) {
			if (find(all(var), s) != var.end()) {
				int indx = find(all(var), s) - var.begin();
				tot.pb(indx + 1), var[indx] = -1;
			}
		}
		if (SZ(tot) == 3) {
			res.pb(tot);
		}
	} while (SZ(tot) == 3);
	cout << SZ(res) << endl;
	for (int i = 0; i < SZ(res); i++) {
		for (int j = 0; j < SZ(res[i]); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}
