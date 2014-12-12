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

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	int n, m;
	cin >> n >> m;
	if (n * 9 < m || (n > 1 && m == 0)) {
		cout << -1 << " " << -1 << endl;
		return 0;
	}
	string tmp = "", ret = "";
	for (int i = 0; i < n; i++) {
		if (m >= 9)
			ret += '9', m -= 9;
		else if (m < 9)
			ret += m + '0', m = 0;
		else
			ret += '0';
	}
	tmp = ret;
	reverse(all(tmp));
	if (tmp[0] == '0' && n != 1) {
		int i = 0;
		while (tmp[i] == '0')
			i++;
		tmp[i]--;
		tmp[0] = '1';
	}
	cout << tmp << " " << ret << endl;
	return 0;
}
