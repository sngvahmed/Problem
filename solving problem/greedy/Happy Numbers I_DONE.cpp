/*
 http://www.spoj.pl/problems/HPYNOS/
 */
#include <iostream>
#include <vector>
#include <set>
#include <sstream>
typedef long long ll;
#define fr(n) for(int i=0;i<int(n);i++)
using namespace std;
int main() {
	string n;
	cin >> n;
	int q = 0;
	while (true) {
		q++;
		stringstream ss;
		ss << n;
		int w = 0;
		ss >> w;
		int sums = 0;
		for (int i = 0; i < n.size(); i++) {
			int e = w % 10;
			w = w / 10;
			sums += e * e;
		}
		if (sums >= 647) {
			cout << -1;
			return 0;
		}
		if (sums == 1) {
			cout << q;
			return 0;
		}
		if (q > 30) {
			cout << -1;
			return 0;
		}
		n = "";
		stringstream nn;
		nn << sums;
		nn >> n;
	}
	return 0;
}
