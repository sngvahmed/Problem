// Mar 10, 2014 Sereja and Contests.cpp
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
int di[] = { 0, 0, 1, -1, 1, -1, 1, -1 }, dj[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
int n = 0, m = 0, co = 0;
vector<pair<string, vector<string> > > var;
string str;
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	int mx[4002];
	MMS(mx,0);
	scanf("%d%d", &n, &m);
	int dv2 = 0;
	FO(i,0,m) {
		int tmp1, tmp2, tmp3;
		cin >> tmp1;
		if (tmp1 == 1) {
			cin >> tmp2 >> tmp3;
			mx[tmp2] = 2, mx[tmp3] = 1;
		} else {
			cin >> tmp2;
			mx[tmp2] = 1;
		}
	}
	int dvm = 0;
	if (dv2 == 0) {
		FO(i,1,n) {
			if (mx[i] == 0)
				dvm++;
		}
	} else {
		FO(i,1,n) {
			if (mx[i] == 0)
				dvm++;
		}
	}
	int how = 0;
	FO(i,2,n) {
		if (mx[i] == 0 && mx[i - 1] ==0 ) {
			mx[i] = 1;
		}
	}
	FO(i,1,n)
		if (mx[i] == 0)
			how++;
	cout << how << " " << dvm << endl;
}
//@CPY::SNGV
