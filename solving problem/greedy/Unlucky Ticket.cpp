//**********************************************************
/*
 * @sngv
 * Unlucky Ticket
 * http://codeforces.com/problemset/problem/160/B
 */
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

#define FO(i, a, x) for(double i = a; i < (double)x; i++)
#define FOR(i, x) FO(i, 0, x)
#define RO(i, a, x) for(double i = a; i >= x; i--)
#define ROF(i, x) for(double i = x; i >= 0; i--)
#define FORIT(it, x) for(typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define FOUND(s, x) find(all(s), x) != s.end()
#define NOTFOUND(s, x) find(all(s), x) == s.end()
#define SZ(x) (double)x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<double, double>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MMS(x, v) memset(x, v, sizeof(x))
#define SQ(x) (x) * (x)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<string> vs;
typedef vector<double> vi;
bool ch1(string x, string y) {
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	FO(i,0,SZ(x))
		if (x[i] >= y[i])
			return 0;
	return 1;
}
bool ch2(string x, string y) {
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	FO(i,0,SZ(x))
		if (x[i] <= y[i])
			return 0;
	return 1;
}
int main() {
	int n;
	scanf("%d", &n);
	string x;
	cin >> x;
	string s1 = x.substr(0, n);
	string s2 = x.substr(n, SZ(x));
	(max(ch1(s1, s2), ch2(s1, s2))) ? cout << "YES" : cout << "NO";
}
