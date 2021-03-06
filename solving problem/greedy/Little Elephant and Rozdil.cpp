#include "bits/stdc++.h"
#include <functional>

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
map<int, vi> var;
int n, m;

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	vi var, vartmp;
	scanf("%d", &n);
	while (n--) {
		cin >> m;
		var.pb(m), vartmp.pb(m);
	}
	sort(all(vartmp));
	if (SZ(vartmp) > 1 && vartmp[0] == vartmp[1]) {
		cout << "Still Rozdil";
		return 0;
	}
	int indx = 0, yet = var[0];
	FO(i , 0 , SZ(var)) {
		if (var[i] < yet)
			yet = var[i], indx = i;
	}
	cout << indx + 1 << endl;
	return 0;
}
