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
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	long long n, avg, r;
	cin >> n >> r >> avg;
	vector<pair<long long, long long> > inp;
	long long emb = 0, tot = 0, totavg = n * avg;
	for (int i = 0; i < n; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		tot += t1;
		inp.pb(mp(t2, t1));
	}
	sort(all(inp));
	int i = 0;
	while (tot < totavg && i < n) {
		long long tmp = min((r - inp[i].S), totavg - tot);
		tot += tmp;
		emb += (tmp * inp[i].F);
		i++;
	}
	cout << emb << endl;
	return 0;
}
