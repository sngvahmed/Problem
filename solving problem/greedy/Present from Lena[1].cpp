//**********************************************************
/*
 * @sngv
 * Present from Lena
 * http://codeforces.com/problemset/problem/118/B
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
void Pres(int x, int r, int t) {
	if (r == x)
		return;
	if (r == 0) {
		FO(i,0,2*t)
			cout << " ";
		cout << 0 << endl;
	} else if (r == x) {
		FO(i,0,r)
			cout << i << " ";
		for (int i = r; i >= 0; i--)
			(i == 0) ? cout << i : cout << i << " ";
		cout << endl;
	} else {
		FO(i,0,2*t)
			cout << " ";
		FO(i,0,r)
			cout << i << " ";
		for (int i = r; i >= 0; i--)
			(i == 0) ? cout << i : cout << i << " ";
		cout << endl;
	}
	Pres(x, r += 1, t -= 1);

	if (r == 0) {
		FO(i,0,2*t)
			cout << " ";
		cout << 0 << endl;
	} else if (r == x) {
		FO(i,0,r)
			cout << i << " ";
		for (int i = r; i >= 0; i--)
			(i == 0) ? cout << i : cout << i << " ";
		cout << endl;
	} else {
		FO(i,0,2*t)
			cout << " ";
		FO(i,0,r)
			cout << i << " ";
		for (int i = r; i >= 0; i--)
			(i == 0) ? cout << i : cout << i << " ";
		cout << endl;
	}
}
int main() {
	int r;
	scanf("%d", &r);
	Pres(r, 0, r);
	FO(i,0,2*r)
		cout << " ";
	cout << 0;

}
