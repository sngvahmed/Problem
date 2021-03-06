// Mar 19, 2014 Marathon.cpp
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
double a, d, n, tmp = 0;
void soliution2() {
	double tot = 0;
	tmp += d;
	tmp = fmod(tmp, 4 * a);
	tot = fmod(tmp, a);
	if (tmp < a)
		printf("%.10lf %.10lf\n", tot, double(0));
	else if (tmp < 2 * a)
		printf("%.10lf %.10lf\n", a, tot);
	else if (tmp < 3 * a)
		printf("%.10lf %.10lf\n", a - tot, a);
	else
		printf("%.10lf %.10lf\n", double(0), a - tot);

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	cin >> a >> d >> n;
	d = fmod(d, 4 * a);
	while (n--) {
		soliution2();
	}
}
//@CPY::SNGV
