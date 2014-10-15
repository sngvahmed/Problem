//============================================================================
// Author      : Ahmed nasser
// Copyright   : http://codeforces.com/contest/334/problem/B
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
bool find(vector<int> x, int num) {
	FO(i,0,SZ(x))
		if (x[i] == num)
			return false;
	return true;
}
int main() {
	// the B
	int n, m;
	pair<int, int> x;
	map<pair<int, int>, bool> y;
	vector<int> llx;
	vector<int> lly;
	bool ttt = true;
	FO(i,0,8) {
		scanf("%d %d", &n, &m);
		x = make_pair(n, m);
		if (y[x] == true) {
			ttt = false;
		}
		y[x] = true;
		if (find(llx, n))
			llx.push_back(n);
		if (find(lly, m))
			lly.push_back(m);

	}
	if (ttt == false) {
		cout << "ugly";
		return 0;
	}
	sort(llx.begin(), llx.end());
	sort(lly.begin(), lly.end());
	x = make_pair(llx[1], lly[1]);
	y[x] = true;
//	cout << llx.size()<<lly.size();
	if (lly.size() > 3 || llx.size() > 3 || lly.size() <= 1
			|| llx.size() <= 1) {
		cout << "ugly";
		return 0;
	}
	for (int it = 0; it != llx.size(); it++) {
		for (int itt = 0; itt != lly.size(); itt++) {
			pair<int, int> tt1;
			tt1 = make_pair(llx[it], lly[itt]);
			if (y[tt1] == false) {
//				cout << tt1.first << " " << tt1.second << endl;
				cout << "ugly";
				return 0;
			}
		}
	}
//	642921
//	922979
//	127181
//	597358
//	828316
//	616833
	cout << "respectable";
}
