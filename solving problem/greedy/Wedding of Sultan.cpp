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
	int n;
	SF(n);
	map<char, int> mp;
	for (int i = 1; i <= n; i++) {
		mp.clear();
		string str;
		cin >> str;
		vector<char> var;
		for (int j = 0; j < SZ(str); j++) {
			if (var.size() && var[var.size() - 1] == str[j]) {
				var.pop_back();
				mp[str[j]]++;
				if (var.size()) {
					mp[var[var.size() - 1]]++;
				}
			} else {
				var.pb(str[j]);
			}
		}
		mp[str[0]]--;
		cout << "Case " << i << endl;
		for (char i = 'A'; i <= 'Z'; i++) {
			if (mp[i])
				cout << i << " = " << mp[i] << endl;
		}
	}
	return 0;
}
