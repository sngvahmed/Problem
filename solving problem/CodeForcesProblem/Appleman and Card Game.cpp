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

typedef unsigned long long ull;

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif

	int x, y;
	scanf("%d%d", &x, &y);

	string var;
	cin >> var;

	sort(all(var));
	vector<pair<int, char> > vec;
	int i = 0;
	while (i < SZ(var)) {
		int j = i + 1, count = 1;
		while (var[i] == var[j] && j < (int) SZ(var))
			j++, count++;
		count = j - i;
		vec.pb(mp(count, var[i])), i = j;
	}

//	for (int i = 0; i < SZ(vec); i++) {
//		cout << vec[i].F << " " << vec[i].S << endl;
//	}
	sort(rall(vec));
	ull tot = 0;
	i = 0;
	while (y) {
		if (y >= vec[i].F) {
			y -= vec[i].F;
			tot += ull(ull(vec[i].F) * ull(vec[i].F));
		} else if (y < vec[i].F) {
			tot += ull(ull(y) * ull(y)), y = 0;
		}
		i++;
	}
	cout << tot << endl;
	return 0;
}
