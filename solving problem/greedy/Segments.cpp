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
	scanf("%d", &n);
	int x, y;
	vector<pair<int, int> > var;
	FO(i , 0 , n) {
		scanf("%d%d", &x, &y), var.push_back(mp(min(x, y), max(x, y)));
	}
	sort(all(var));
	FO(i , 1 , SZ(var)) {
		x = var[i].F, y = var[i].S;
		int xt = var[i - 1].F, yt = var[i - 1].S;
		if (yt < x || y < xt) {
			continue;
		}
		vector<int> tmp;
		tmp.pb(x), tmp.pb(y), tmp.pb(xt), tmp.pb(yt);
		sort(all(tmp));
		var[i] = var[i - 1] = mp(tmp[0], tmp[3]);
		var.erase(var.begin() + i - 1), i--;
	}
	int mx = 0;
//	cout << SZ(var) << endl;
	FO(i , 0 , SZ(var)) {
		mx += var[i].S - var[i].F;
	}
	cout << mx << endl;
	return 0;
}

