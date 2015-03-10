//============================================================================
// Author      : Ahmed nasser
// Version     : 449
// Copyright   : 75
// Description : 521 DIV2 -> 500
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
class RedAndGreen {
public:
	int minPaints(string row) {
		int su, r, g;
		r = g = su = 0;
		FO(i,0,row.size()) {
			row[i] == 'R' ? r++ : g++;
		}
		//RRRGGGRGGGRGGRRRGGRRRGR
		int gr, rr;
		gr = rr = 0;
		int sum = 0;
		bool ch = true;
		if (g == 0 || r == 0)
			return 0;
		for (int i = 0; i < row.size() && su < r; i++) {
			if (row[i] == 'G') {
				cout << i << " ";
				for (int n = i; n < row.size() && row[i] != 'R'; n++, i++)
					gr++;
				cout << i << " ";
				for (int n = i; n < row.size() && row[i] != 'G'; n++, i++)
					rr++;
				cout << i << " ";
				i--;
				if (min(gr, rr) == gr)
					ch = false;
				if (gr == 0 && ch == true)
					gr = rr;
				sum += min(gr, rr);
				gr = rr = 0;
				cout << endl;
			} else {
				cout << i << " ";
				for (int n = i; n < row.size() && row[i] != 'G'; n++, i++)
					rr++;
				cout << i << " ";
				for (int n = i; n < row.size() && row[i] != 'R'; n++, i++)
					gr++;
				cout << i << " ";
				i--;
				sum += min(gr, rr);
				gr = rr = 0;
				cout << endl;
			}
		}
		return sum;
	}
};
