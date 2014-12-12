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

bool search(string x1, string x2) {
	for (int i = 0; i < SZ(x1) - SZ(x2); i++)
		if (x1[i] == x2[0])
			if (x1.substr(i, SZ(x2)) == x2)
				return 1;
	return 0;
}

bool searcboth(string x, string y) {
	int i, j;
	i = j = 0;
	while (i < SZ(x) && j < SZ(y))
		(x[i] == y[j]) ? j++ : i++;
	return (j == SZ(y)) ? 1 : 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string x, y;
	cin >> x >> y;
	if (SZ(y) > SZ(x)) {
		cout << "need tree" << endl;
		return 0;
	} else if (search(x, y) || searcboth(x, y)) {
		cout << "automaton" << endl;
		return 0;
	} else {
		sort(all(x)), sort(all(y));
		if (x == y) {
			cout << "array" << endl;
			return 0;
		} else {
			if (searcboth(x, y)) {
				cout << "both" << endl;
				return 0;
			}
		}
	}
	cout << "need tree" << endl;

	return 0;
}
