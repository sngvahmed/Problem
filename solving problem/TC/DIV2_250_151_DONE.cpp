//============================================================================
// Author      : Ahmed nasser
// Version     : 151 div2 250
// score       : 130
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
#define st string

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<string> vs;
typedef vector<int> vi;
class PrefixCode {
public:
	bool CHprefix(st x, st y) {
		FO(i,0,min(SZ(x),SZ(y))) {
			if (x[i] != y[i])
				return false;
		}
		return true;
	}
	string isOne(vector<st> words) {
		int r = 1000000;
		FO(i,0, SZ(words)) {
			FO(e,0,SZ(words)) {
				if (i != e && CHprefix(words[i], words[e])) {
					if (SZ(words[i]) < SZ(words[e]))
						r = min(r, i);
					else
						r = min(r, e);
				}
			}
		}
		if (r == 1000000)
			return "Yes";
		words[0] = "No, ";
		if (r == 0) {
			words[0] += '0';
		}
		stringstream ss;
		ss << r;
		string d;
		ss >> d;
		FO(i,0,SZ(d))
			words[0] += d[i];
		return words[0];
	}
}
;
