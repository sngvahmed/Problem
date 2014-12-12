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
	string x1, x2;
	cin >> x1 >> x2;
	int n;
	cin >> n;
	map<int, int> k1, k2;
	map<pair<int, char>, int> vis;
	while (n--) {
		int m, num;
		char a, s;
		cin >> m >> a >> num >> s;
		if (vis[mp(num, a)] == 1)
			continue;
		if (s == 'r' && vis[mp(num, a)] == 0) {
			vis[mp(num, a)] = 1;
			if (a == 'a') {
				cout << x2 << " " << num << " " << m << endl;
			} else
				cout << x1 << " " << num << " " << m << endl;
			continue;
		}
		if (a == 'a' && vis[mp(num, a)] == 0) {
			k1[num]++;
			if (k1[num] == 2) {
				vis[mp(num, a)] = 1;
				cout << x2 << " " << num << " " << m << endl;
			}
		} else if (a == 'h') {
			k2[num]++;
			if (k2[num] == 2 && vis[mp(num, a)] == 0) {
				vis[mp(num, a)] = 1;
				cout << x1 << " " << num << " " << m << endl;
			}
		}
	}
	return 0;
}
