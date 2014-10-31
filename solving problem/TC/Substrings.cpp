//Mar 4, 2014 :: Substrings.cpp
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
int n = 0, m = 0, co = 0;
vs var;
bool ch(string sub, string str) {
	return ((int) str.find(sub) != -1) ? 1 : 0;
}
bool CH(string sub) {
	FO(i,0,SZ(var)) {
		string str = var[i], subr = sub;
		reverse(str.begin(), str.end());
		reverse(all(subr));
		if (ch(sub, var[i])) {
			continue;
		}
		if (ch(sub, str)) {
			continue;
		}
		if (ch(subr, var[i])) {
			continue;
		}
		if (ch(subr, str)) {
			continue;
		}
		return 0;
	}
	return 1;
}
int FUK(string les) {
	int ret = 0;
	FO(i,0,SZ(les)) {
		FO(e,i,SZ(les)) {
			bool check = true;
			string sub = les.substr(i, e + 1);
			if (CH(sub)) {
				if (ret < SZ(sub)) {
					ret = SZ(sub);
				}
				check = false;
			}
			if (check)
				break;
		}
	}
	return ret;
}
int main() {
	int to;
	scanf("%d", &to);
	while (to--) {
		scanf("%d", &n);
		var.clear(), var.resize(n);
		FO(i,0,n) {
			cin >> var[i];
		}
		string les = "";
		FO(i,0,SZ(var)) {
			if (les == "" || SZ(var[i]) < SZ(les))
				les = var[i];
		}
		string tmp = les;
		reverse(all(tmp));
		cout << max(FUK(tmp), FUK(les)) << endl;
	}
	return 0;
}
// COPY@SNGV :: Mar 4, 2014 :: sngv
