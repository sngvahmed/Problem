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

int n;
// change mod ******************************
long long toDecimal(string s, int base) {
	long long v, i, result = 0;
	for (i = 0; i < (int) s.size(); i++) {
		(s[i] >= '0' && s[i] <= '9') ? v = s[i] - '0' : v = s[i] - 'A' + 10, result =
				result * base + v;
	}
	return result;
}

string toBase(long long num, int base) {
	if (num == 0)
		return "0";
	string str;
	while (num != 0) {
		int nlet = num % base;
		num /= base;
		if (nlet < 0)
			num++, nlet += (-1 * base);
		if (nlet < 10)
			str += (nlet + '0');
		else
			str += (nlet - 10 + 'A');
	}
	reverse(str.begin(), str.end());
	return str;
}
// ****************************************

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
//	ios::sync_with_stdio(false);
//	cin.tie(NULL), cout.tie(NULL);
	SF(n);
	while (n--) {
		long long num1, num2;
		cin >> num1 >> num2;
//		cout << num1 << " " << num2 << " ";
		string n1 = toBase(num1, 2), n2 = toBase(num2, 2);
		if (num1 == num2) {
			cout << num1 << endl;
		} else if (SZ(n1) != SZ(n2)) {
			string ret = "";
			bool check = false;
			for (int i = 0; i < SZ(n2); i++) {
				if (n2[i] == '0') {
					check = true;
					break;
				}
			}
			if (!check) {
				cout << num2 << endl;
				continue;
			}
			for (int i = 0; i < SZ(n2) - 1; i++)
				ret += '1';
			cout << toDecimal(ret, 2) << endl;
		} else {
			string ret = "";
			bool check = true;
			for (int i = SZ(n2) - 1; i >= 0; i--) {
				if (n2[i] == '1' && check == false)
					break;
				else if ((n2[i] == '0' && n1[i] == '1')
						|| (n2[i] == '0' && n1[i] == '0'))
					check = false, ret += '1';
				else if (n2[i] == '1')
					ret += '1';
				else if (n2[i] == '0')
					break;
			}
			int count = SZ(n2) - SZ(ret);
			while (count--)
				ret += '0';
			reverse(all(ret));
			ret[0] = '1';
			cout << toDecimal(ret, 2) << endl;
		}

	}

	return 0;
}
