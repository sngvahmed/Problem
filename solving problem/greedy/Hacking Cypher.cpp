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
typedef unsigned long long int ull;
vector<ull> r1, r2;
string str;
ull a, b;
void RUN() {
	ull tmp = 1, oldVal = 0;
	for (int i = 0; i < SZ(str); i++)
		r1.pb(((oldVal * 10) + (str[i] - '0')) % a), oldVal = r1[i];
	oldVal = 0;
	int c = 0;
	for (int i = SZ(str) - 1; i >= 0; i--) {
		ull tot = (oldVal + (tmp * (str[i] - '0'))) % b;
		r2.pb(tot), oldVal = r2[c], tmp = (tmp * 10) % b, c++;
	}
	reverse(all(r2));
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	cin >> str >> a >> b;
	RUN();
	for (int i = 0; i < SZ(r1) - 1; i++) {
		if (r1[i] == 0 && r2[i + 1] == 0) {
			string t1 = str.substr(0, i + 1);
			string t2 = str.substr(i + 1, SZ(str));
			if (t1[0] == '0' || t2[0] == '0')
				continue;
			cout << "YES" << endl;
			cout << t1 << endl;
			cout << t2 << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
