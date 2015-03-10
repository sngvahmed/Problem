//============================================================================
// Author      : Ahmed nasser
// Version     : 149 div2 250
// score       : 169
//============================================================================
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
class FormatAmt {
public:
	int SIZ(int x) {
		stringstream ss;
		string d;
		ss << x, ss >> d;
		return SZ(d);
	}
	string amount(int DOL, int CEN) {
		int r = SIZ(DOL), m = DOL, e = 0;
		vector<string> ret;
		string x = "";
		while (DOL != 0) {
			if (e == 3) {
				e = 0, ret.push_back(x), x = "";
			}
			x += char(DOL % 10 + '0'), DOL /= 10;
			e++;
		}
		ret.push_back(x);
		x = "$";
		if (m == 0)
			x += '0';
		for (int i = SZ(ret) - 1; i >= 0; i--) {
			for (int d = SZ(ret[i]) - 1; d >= 0; d--) {
				x += ret[i][d];
			}
			x += ',';
		}
		x[SZ(x) - 1] = '.';
		stringstream ss;
		ss << CEN;
		string dd = "";
		ss >> dd;
		if (dd.size() == 1) {
			x += '0';
			FO(i,0,SZ(dd)) {
				x += dd[i];
			}
		} else {
			FO(i,0,SZ(dd)) {
				x += dd[i];
			}
		}
		return x;
	}
}
;
