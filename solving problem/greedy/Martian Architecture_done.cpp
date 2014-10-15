//============================================================================
// Author      : Ahmed nasser
// Copyright   : B. Martian Architecture
// name 	   : http://codeforces.com/problemset/problem/57/B
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
#define FOUND(s, x) find(allx(s), x) != s.end()
#define NOTFOUND(s, x) find(allx(s), x) == s.end()
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>
#define allx(x) x.begin(), x.end()
#define rallx(x) x.rbegin(), x.rend()
#define MMS(x, v) memset(x, v, sizeof(x))
#define SQ(x) (x) * (x)

typedef long long llx;
typedef unsigned long long ullx;
typedef unsigned long ul;
typedef vector<string> vs;
typedef vector<int> vi;
int main() {
	int n1, n2, k;
	cin >> n1 >> n2 >> k;

	vector<int> a, b, c;
	for (int i = 0; i < n2; i++) {
		int tm1, tm2, tm3;
		cin >> tm1 >> tm2 >> tm3;
		a.push_back(tm1);
		b.push_back(tm2);
		c.push_back(tm3);
	}
	llx res = 0;
	FO(i,0,k) {
		int t;
		cin >> t;
		for (int j = 0; j < n2; j++)
			if (a[j] <= t && t <= b[j])
				res += c[j] + t - a[j];
	}

	cout << res << endl;
}
