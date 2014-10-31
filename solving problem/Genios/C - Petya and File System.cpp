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
int n, m;
map<string, int> vc;
set<string> ret;
map<pair<char, string>, pair<int, int> > cnt;

bool validate(int i, int j) {
	return (i >= 0 && j >= 0 && i < n && j < m) ? 1 : 0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
//	freopen("o.txt", "wt", stdout);
#endif
	string num, tmp, fl, le, h;
	int indx1 = 0, indx2 = 0, rz;
	while (cin >> num) {
		bool ch = 1;
		char bb = num[0];
		tmp = "", tmp += num[0], num.erase(0, 3), ret.insert(tmp), fl = tmp, rz =
		SZ(num) - 1;
		while (num[rz] != '\\')
			rz--;
		string me = num.substr(rz + 1, SZ(num));
		while (num.size()) {
			int i = 0;
			while (num[i] != '\\' && i < num.size())
				i++;
			string tm = num.substr(0, i);
			stringstream ss;

			if (ch)
				ch = 0, h = tm;
			num.erase(0, i + 1), fl = fl + tm;
			if (SZ(fl) != 1 && vc[fl] == 0) {
				(tm == me) ?
						cnt[make_pair(bb, h)].second++ :
						cnt[make_pair(bb, h)].first++;
				vc[fl] = 1;
			}
			indx2 = max(indx2, cnt[make_pair(bb, h)].first), indx1 = max(indx1,
					cnt[make_pair(bb, h)].second);
		}
	}
	cout << --indx2 << " " << indx1 << endl;
	return 0;
}
