// Mar 20, 2014 Multiplication.cpp
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
string CAL(string x) {
	return "0" + x;
}
long long toInt(string x) {
	stringstream ss;
	long long ret;
	ss << x, ss >> ret;
	return ret;
}
string toString(long long x) {
	stringstream ss;
	string ret;
	ss << x, ss >> ret;
	return ret;
}
long long combine(long long p1, long long p2, long long p3, int n) {
	return ((pow(double(10), n)) * p1)
			+ ((p3 - p2 - p1) * pow(double(10), n / 2)) + p2;
}
long long divide(string x, string y) {
	if (SZ(x) == 1 || SZ(y) == 1)
		return toInt(x) * toInt(y);
	string xl = x.substr(0, SZ(x) / 2), xr = x.substr(SZ(x) / 2, SZ(x));
	string yl = y.substr(0, SZ(y) / 2), yr = y.substr(SZ(y) / 2, SZ(y));
	long long p1 = divide(xl, yl), p2 = divide(xr, yr);
	long long p3 = divide(toString(toInt(xr) + toInt(xl)),
			toString(toInt(yr) + toInt(yl)));
	return combine(p1, p2, p3, SZ(x));
}
void RUN(string x, string y) {
	if (SZ(x) % 2 != 0)
		x = CAL(x);
	if (SZ(y) % 2 != 0)
		y = CAL(y);
	cout << x << "*" << y << " :: " << divide(x, y) << endl;
}
int main() {
	RUN("10011", "111");
}
//@CPY::SNGV
