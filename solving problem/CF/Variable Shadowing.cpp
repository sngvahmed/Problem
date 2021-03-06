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
vector<vector<pair<char, pair<int, int> > > > var(1);

map<char, int> global, gsatr;

pair<int, int> fd(char x) {
	for (int i = SZ(var) - 1; i >= 0; i--) {
		for (int j = SZ(var[i]) - 1; j >= 0; j--) {
			if (var[i][j].F == x) {
				return mp(var[i][j].S.F, var[i][j].S.S);
			}
		}
	}
	return mp(-1, -1);
}

int main() {
//	freopen("test.in", "rt", stdin);

	int n;
	cin >> n;
	int lvl = 0;
	for (int i = 0; i <= n; i++) {
		string tmp;
		getline(cin, tmp);
		for (int j = 0; j < SZ(tmp); j++) {
			if (tmp[j] == '{') {
				vector<pair<char, pair<int, int> > > tmp;
				var.pb(tmp);
				lvl++;
			} else if (tmp[j] == '}') {
				var.erase(var.end());
				lvl--;
			} else if (tmp[j] != ' ') {
				pair<int, int> sr = fd(tmp[j]);
				if (sr == mp(-1, -1)) {
					var[lvl].pb(mp(tmp[j], mp(i, j)));
				} else {
					printf(
							"%d:%d: warning: shadowed declaration of %c, the shadowed position is %d:%d\n",
							i, j + 1, tmp[j], sr.F, sr.S + 1);
					var[lvl].pb(mp(tmp[j], mp(i, j)));
				}
			}
		}
	}
	return 0;
}
