//http://codeforces.com/problemset/problem/26/A
// almost prime
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
bool primes[1000001];
int e = 0;
int arr[100001];
void initPrimes() {
	memset(primes, true, sizeof(primes));
	primes[0] = primes[1] = false;
	for (int i = 2; i <= 1000000; i++) {
		if (primes[i]) {
			arr[e] = i;
			e++;
			for (int j = 2; i * j <= 1000000; j++)
				primes[i * j] = false;
		}
	}
}

int main() {
	initPrimes();
	int x, r;
	cin >> x;
	int ss = 0;
	while (x > 4) {
		int e = 0;
		r = x - 1;
		while (r > 0) {
			if (primes[r] && x % r == 0) {
				e++;
			}
			r--;
		}
//		cout << x << e << endl;
		if (e == 2)
			ss++;
		x--;
	}
	cout << ss;
	return 0;
}
