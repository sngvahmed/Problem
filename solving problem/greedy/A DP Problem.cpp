// Mar 7, 2014 A DP Problem.cpp
#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
#include <memory.h>
#include <climits>
#include <math.h>

using namespace std;

#define FO(i, a, x) for(int i = a; i < (int)x; i++)
#define FOR(i, x) FO(i, 0, x)
#define RO(i, a, x) for(int i = a; i >= x; i--)
#define ROF(i, x) for(int i = x; i >= 0; i--)
#define FORIT(it, x) for(typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define FOUND(s, x) find(all(s), x) != s.end()
#define NOTFOUND(s, x) find(all(s), x) == s.end()
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MMS(x, v) memset(x, v, sizeof(x))
#define SQ(x) (x) * (x)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<string> vs;
typedef vector<int> vi;
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	int n;
	scanf("%d", &n);
	while (n--) {
		int xf = 0, xb = 0, nf = 0, nb = 0;
		char tmp = '+', nm;
		string str, app = "";
		cin >> str;
		int i = 0;
		if (str[i] == '-') {
			tmp = str[i];
			i++;
		}
		int de;
		stringstream ss;
		while (tmp != '=') {
			nm = str[i];
			if (nm == 'x') {
				ss.clear(), ss << app, ss >> de;
				if (app == "") {
					if (tmp == '+')
						xb += 1;
					else
						xb -= 1;
				} else if (tmp == '+')
					xb += de;
				else if (tmp == '-')
					xb -= de;
				i++;
				if (str[i] == '=')
					break;
				tmp = str[i], app = "";
			} else if (nm == '=') {
				ss.clear(), ss << app, ss >> de;
				if (tmp == '+')
					nb += de;
				else if (tmp == '-')
					nb -= de;
				app = "";
				break;
			} else if (nm == '-' || nm == '+') {
				ss.clear(), ss << app, ss >> de;
				if (tmp == '+')
					nb += de;
				else if (tmp == '-')
					nb -= de;
				tmp = nm, app = "";
			} else
				app += nm;
			i++;
		}
		tmp = '+', i++, app = "", ss.clear();
		if (str[i] == '-') {
			tmp = str[i];
			i++;
		}
		while (i < SZ(str)) {
			nm = str[i];
			if (nm == 'x') {
				ss.clear(), ss << app, ss >> de;
				if (app == "")
					(tmp == '+') ? xf += 1 : xf -= 1;
				else if (tmp == '+')
					xf += de;
				else if (tmp == '-')
					xf -= de;
				i++;
				if (i >= SZ(str))
					break;
				tmp = str[i], app = "";
			} else if (nm == '-' || nm == '+') {
				ss.clear(), ss << app, ss >> de;
				if (tmp == '+')
					nf += de;
				else if (tmp == '-')
					nf -= de;
				tmp = nm, app = "";
			} else
				app += nm;
			i++;
			if (i >= SZ(str)) {
				ss.clear(), ss << app, ss >> de;
				if (tmp == '+')
					nf += de;
				else if (tmp == '-')
					nf -= de;
				tmp = nm, app = "";
			}
		}
//		cout << nb << " " << xb << "::" << nf << " " << xf << endl;
		xb = xb - xf;
		nb = nf - nb;
		if (nb == 0 && xb == 0) {
			cout << "IDENTITY" << endl;
		} else if (xb == 0 && nb != 0) {
			cout << "IMPOSSIBLE" << endl;
		} else if (nb == 0 && xb != 0)
			cout << 0 << endl;
		else {
			if (double(nb) / double(xb) < 0
					&& double(nb) / double(xb)
							== int(double(nb) / double(xb)) - 0.5) {
				cout << int(double(nb) / double(xb)) - 1 << endl;
			} else if (double(nb) / double(xb) >= 0
					&& double(nb) / double(xb)
							== int(double(nb) / double(xb)) + 0.5) {
				cout << int(double(nb) / double(xb)) + 1 << endl;
			} else
				cout << floor(double(nb) / double(xb)) << endl;
		}
	}
}
//@CPY::SNGV
