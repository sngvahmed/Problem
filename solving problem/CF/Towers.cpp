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
	int n, m;
	SF(n), SF(m);
	vector<pair<int, int> > var;
	for (int i = 0; i < n; i++) {
		int tmp;
		SF(tmp), var.pb(mp(tmp, i));
	}
	int i = 0;
	vector<pair<int, int> > ret;
	while (m--) {
		sort(all(var));
		if (var[SZ(var) - 1].F == var[0].F
				|| (var[SZ(var) - 1].F - var[0].F) == 1)
			break;
		var[SZ(var) - 1].F--, var[0].F++;
		ret.pb(mp(var[SZ(var) - 1].S, var[0].S));
		i++;
	}
	sort(all(var));
	cout << var[SZ(var) - 1].F - var[0].F << " " << i << endl;
	for (int j = 0; j < SZ(ret); j++)
		cout << ret[j].F + 1 << " " << ret[j].S + 1 << endl;
	return 0;
}
