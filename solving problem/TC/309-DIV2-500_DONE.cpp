//============================================================================
// Author      : Ahmed nasser
// Version     : 1
// Copyright   : COPY RITHT To :: ahmed nasser saleh
// Description : 204
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
class ScoreRecomposition {
public:
	int minError(string questions, int score) {
		vector<pair<int, char> > v;
		FO (i,0,questions.size())
			v.push_back(make_pair(i, questions[i]));
		int r = 1000000000;
		do {
			int tm=0, a=0;
			FO(i,0,SZ(v)) {
				tm = max(tm, abs(i - v[i].first));
				if (v[i].second == 'C')
					a += i + 1;
			}
			if (a == score)
				r = min(tm, r);
		} while (next_permutation(v.begin(), v.end()));
		if (r == 1000000000)
			return -1;
		return r;
	}
};
