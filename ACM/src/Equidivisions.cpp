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

string toBase(long long num, int base) {
	if (num == 0)
		return "0";
	string str;
	while (num != 0) {
		int nlet = num % base;
		num /= base;
		if (nlet < 0) //for negative base
			num++, nlet += (-1 * base);
		if (nlet < 10)
			str += (nlet + '0');
		else
			str += (nlet - 10 + 'A');

	}
	reverse(str.begin(), str.end());
	return str;
}

long long toDecimal(string s, int base) {
	long long v, i, result = 0;
	for (i = 0; i < (int) s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			v = s[i] - '0';
		else
			v = s[i] - 'A' + 10;
		result = result * base + v;
	}
	return result;
}
int find(int b, int e, char f, string str) {
	for (int i = b; i < min(e, SZ(str)); i++) {
		if (str[i] == f)
			return i;
	}
	return -1;
}
int main() {
	long long num1, num2;
	int n;
	cin >> n;
	while (n-- && cin >> num1 >> num2) {
		string n1 = toBase(num1, 2), n2 = toBase(num2, 2);
		if (num1 == num2) {
			cout << num1 << endl;
		} else if (find(0, SZ(n2), '0', n2) == -1) {
			cout << num2 << endl;
		} else if (SZ(n1) != SZ(n2)) {
			string tmp = "";
			for (int i = 1; i < SZ(n2) ; i++)
				tmp += '1';
			cout << toDecimal(tmp, 2) << endl;
		} else {
			for (int i = SZ(n1) - 1; i >= 0; i--) {
				n1[i] = '1';
				if (toDecimal(n1, 2) > num2)
					n1[i] = '0';
			}
			cout << toDecimal(n1, 2) << endl;
		}
	}
	return 0;
}
