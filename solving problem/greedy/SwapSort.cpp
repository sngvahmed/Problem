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
vector<int> var;
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	int n;
	SF(n);
	vector<pair<int, int> > var;
	var.resize(n);
	for (int i = 0; i < n; i++)
		SF(var[i].F), var[i].S = i;
	sort(all(var));
	cout << n << endl;
	for (int i = 0; i < SZ(var); i++) {
		for (int l = 0; l < SZ(var); l++) {
			if (i == var[l].S) {
				cout << i << " " << var[i].S << endl;
				swap(var[l].S, var[i].S);
				break;
			}
		}
	}
	return 0;
}
