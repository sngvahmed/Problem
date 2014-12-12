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

typedef unsigned long long ull;
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	int n = 6;
	map<string, ull> mob;
	map<string, int> time;
	vector<string> typ;
	while (n--) {
		string name, type;
		ull price;
		cin >> name >> type >> price;
		if (mob[type] == 0 || mob[type] > price)
			mob[type] = price;
		time[type]++, typ.pb(type);
	}
	string ret = "";
	ret = typ[0];
	for (int i = 0; i < SZ(typ); i++) {
		string m = typ[i];
		if (time[m] < time[ret]) {
			continue;
		} else if (time[m] > time[ret]) {
			ret = m;
		} else if (mob[m] < mob[ret]) {
			ret = m;
		}
	}
	cout << ret << endl;

	return 0;
}
