//Mar 4, 2014 :: That is Your Queue.cpp
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
int di[] = { 0, 0, 1, -1, 1, -1, 1, -1 }, dj[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
int n = 0, m = 0, co = 0;
vector<pair<string, vector<string> > > var;
string str;
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	scanf("%d", &n);
	cin.ignore();
	while (n--) {
		string strr;
		getline(cin, strr);
		bool che = false;
		while (true) {
			if (getline(cin, str).eof())
				che = true;
			if (str == "/n" || str == "") {
				break;
			}
			pair<string, vector<string> > tm;
			string tmp = "";
			int i = 0, ct = 0;
			tm.S.pb(strr);
			FO(e,0,3) {
				while (str[i] != ',') {
					if (e != 2)
						ct++;
					tmp += str[i], i++;
				}
				tmp += ' ', i++;
			}
			tm.F = tmp.substr(ct + 2, SZ(tmp)), tm.S.pb(tmp);
			while (i < SZ(str)) {
				while (i < SZ(str) && (str[i] == '.' || str[i] == ',')) {
					i++;
				}
				tmp = "";
				while (i < SZ(str) && str[i] != '.' && str[i] != ',') {
					tmp += str[i], i++;
				}
				if (tmp.size() != 0)
					tm.S.pb(tmp);
			}
			var.pb(tm);
			if (che)
				break;
		}
		str = "";
	}
	sort(var.begin(), var.end());
	cout << "----------------------------------------" << endl;
	FO(i, 0, SZ(var)) {
		cout << var[i].S[1].substr(0, SZ(var[i].S[1]) - 1) << endl;
		cout << var[i].S[2] << endl;
		cout << "Department: " << var[i].S[0] << endl;
		cout << "Home Phone: " << var[i].S[3] << endl;
		cout << "Work Phone: " << var[i].S[4] << endl;
		cout << "Campus Box: " << var[i].S[5] << endl;
		if (i != SZ(var) - 1) {
			cout << "----------------------------------------" << endl;
		}
	}
	return 0;
}
// COPY@SNGV :: Mar 4, 2014 :: sngv