//============================================================================
// Author      : Ahmed nasser
// Version     : 147 div2 250
// score       : 120
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
class CCipher {
public:
	char SHIFTBK(char x, int n) {
		n = n % 28;
		if (x >= 'a' && x <= 'z') {
			int sum = int(x) - n;
			if (sum >= 'a')
				return x - n;
			else {
				n = n - (x - 'a');
				return 'z' - n + 1;
			}
		}
		if (x >= 'A' && x <= 'Z') {
			int sum = int(x) - n;
			if (sum >= 'A')
				return x - n;
			else {
				n = n - (x - 'A');
				return 'Z' - n + 1;
			}
		}
	}
	string decode(string CI, int SH) {
		FO(i,0,SZ(CI)) {
			CI[i] = SHIFTBK(CI[i], SH);
		}
		return CI;
	}
}
;

