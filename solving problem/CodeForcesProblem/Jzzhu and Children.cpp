// @Sep 13, 2014
// @CPY sngv ..... Jzzhu and Children.cpp 
#include "bits/stdc++.h"
#include <functional>
#include <ext/numeric> // for power long long 

using namespace std;

#define FO(i, a, x) for(int i = a; i < (int)x; i++)
#define FOR(i, x) FO(i, 0, x)
#define RO(i, a, x) for(int i = a; i >= x; i--)
#define ROF(i, x) for(int i = x; i >= 0; i--)
#define FORIT(it, x) for(typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define FOUND(s, x) find(all(s), x) != s.end()
#define NOTFOUND(s, x) find(all(s), x) == s.end()
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MMS(x, v) memset(x, v, sizeof(x))
#define SQ(x) (x) * (x)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, vi> pi;
typedef pair<int, int> vp;
typedef pair<int, pair<int, int> > Hamada;

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	vector<pair<int, int> > var;
	int n, m;
	cin >> n >> m;
	FO(i , 0 , n)
	{
		int x;
		cin >> x, var.pb(mp(x, i));
	}

	while (var.size() != 1) {
		var[0].F -= m;
		if (var[0].F <= 0)
			var.erase(var.begin());
		else {
			pair<int, int> tmp = var[0];
			var.erase(var.begin()), var.pb(tmp);
		}
	}
	cout << var[0].S + 1 << endl;
	return 0;
}
