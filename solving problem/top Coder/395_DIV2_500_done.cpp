//============================================================================
// Author      : Ahmed nasser
// Version     : 1
// Copyright   : 150
// Description : 395_DIV2_500_DONE
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
class StreetWalking {
public:
	bool iseven(long long x) {
		if (x % 2 == 0)
			return 1;
		return 0;
	}
	long long minTime(int X, int Y, int wt, int st) {
		long long x = max(abs(X), abs(Y)), y = min(abs(Y), abs(X));
		if (wt * 2 <= st) {
			return (x + y) * wt;
		} else {
			if (iseven(abs(y - x)))
				return (abs(y - x) * min(wt, st)) + (y * st);
			if (wt <= st)
				return ((abs(y - x)) * wt) + (y * st);
			return ((abs(y - x) - 1) * st) + (y * st) + wt;
		}
	}
};
