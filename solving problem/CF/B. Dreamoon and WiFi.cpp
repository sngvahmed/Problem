//http://codeforces.com/contest/476/problem/B
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
string ans, pr;
int t1, t2;
void rec(int i, int ansn, int prn) {
	if (i == SZ(pr)) {
		(prn == ansn) ? t1++ : t2++;
		return;
	}
	if (pr[i] == ans[i]) {
		rec(i + 1, ansn, prn);
	} else if (pr[i] == '?') {
		rec(i + 1, (ans[i] == '+') ? ansn + 1 : ansn - 1, prn + 1);
		rec(i + 1, (ans[i] == '+') ? ansn + 1 : ansn - 1, prn - 1);
	} else {
		rec(i + 1, (ans[i] == '+') ? ansn + 1 : ansn - 1,
				(pr[i] == '+') ? prn + 1 : prn - 1);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	cin >> ans >> pr;
	t1 = t2 = 0;
	rec(0, 0, 0);
	cout << setprecision(12) << fixed << double(t1) / double(t1 + t2) << endl;
	return 0;
}
