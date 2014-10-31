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
int di[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dj[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
string ret = "ABCDEF ";
bool vis[189][189];
int lvl = -1;
class PilingRectsDiv2 {
public:
	int getmax(vector<int> X, vector<int> Y, int limit) {
		int co = 0;
		for (int i = 0; i < SZ(X); i++) {
			int cont = 0, mx = X[i], my = Y[i];
			if ((X[i] * Y[i]) >= limit)
				for (int e = 0; e < SZ(X); e++) {
					if ((X[i] <= X[e] && Y[i] <= Y[e])
							|| (X[i] <= Y[e] && Y[i] <= X[e])) {
						cont++;
					}
					if ((min(mx, X[e]) * min(my, Y[e])) >= limit) {
						mx = min(mx, X[e]), my = min(my, Y[e]);
						cont++;
					}
				}
			co = max(cont, co);
		}
		if (co == 0)
			return -1;
		else
			return co;
	}
};
