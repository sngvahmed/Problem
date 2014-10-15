// Mar 10, 2014 Team.cpp
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
	scanf("%d%d", &n, &m);
	if (n > m + 1) {
		cout << -1;
	} else if (n == m) {
		FO(i,0,n+m)
			if (i % 2 == 0)
				cout << 1;
			else
				cout << 0;
	} else if (n == m + 1 || (2 * n) == m || ((2 * n) + 2) == m || n + 1 == m
			|| double(m) / double(n) <= 2.0||((2 * n) + 1) == m) {
		if (n > m) {
			int r = n, k = 0;
			m = m - r;
			if (m < 0)
				m = 0;
			FO(i,0,r) {
				if (k % 2 != 0)
					cout << 1, i--;
				else
					cout << 0;
				k++;
			}
		} else {
			int r = n + 1, k = 0;
			m = m - r;
			if (m < 0)
				m = 0;
			FO(i,0,r) {
				if (k % 2 == 0)
					(m) ? m--, cout << 11 : cout << 1;
				else
					cout << 0, i--;
				k++;
			}
		}
	} else
		cout << -1 << endl;
}
//@CPY::SNGV
