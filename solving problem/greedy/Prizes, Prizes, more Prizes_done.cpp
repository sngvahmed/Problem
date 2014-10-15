//============================================================================
// Author      : Ahmed nasser
// Version     :
// Copyright   :  D. Prizes, Prizes, more Prizes
//============================================================================
//http://codeforces.com/problemset/problem/208/D
//http://ideone.com/WGakse
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

using namespace std;

#define FO(i, a, x) for(long long i = a; i < (long long)x; i++)
#define FOR(i, x) FO(i, 0, x)
#define RO(i, a, x) for(long long i = a; i >= x; i--)
#define ROF(i, x) for(long long i = x; i >= 0; i--)
#define FORIT(it, x) for(typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define FOUND(s, x) find(all(s), x) != s.end()
#define NOTFOUND(s, x) find(all(s), x) == s.end()
#define SZ(x) (long long)x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<long long, long long>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MMS(x, v) memset(x, v, sizeof(x))
#define SQ(x) (x) * (x)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<string> vs;
typedef vector<long long> vi;

int main() {
	/*3
	 3 10 4
	 2 4 10 15 20*/
	long long n ;
//	cout << n ;
	cin >> n;
	long long num[n];
	for (long long i = 0; i < n; i++)
		cin >> num[i];
	long long nm[5];
	for (long long i = 0; i < 5; i++)
		cin >> nm[i];
	long long sum = 0;
	long long nmsum[5] = { 0 };
	for (int i = 0; i < n; i++) {
		num[i] += sum;
		if (nm[4] <= num[i]) {
			nmsum[4] += (num[i] / nm[4]);
			num[i] = num[i] % nm[4];
		}
		if (nm[3] <= num[i]) {
			nmsum[3] += (num[i] / nm[3]);
			num[i] = num[i] % nm[3];
		}
		if (nm[2] <= num[i]) {
			nmsum[2] += (num[i] / nm[2]);
			num[i] = num[i] % nm[2];
		}
		if (nm[1] <= num[i]) {
			nmsum[1] += (num[i] / nm[1]);
			num[i] = num[i] % nm[1];
		}
		if (nm[0] <= num[i]) {
			nmsum[0] += (num[i] / nm[0]);
			num[i] = num[i] % nm[0];
		}
		sum = num[i];
	}
	for (int i = 0; i < 5; i++)
		cout << nmsum[i] << " ";

	cout << "\n" << sum;
	return 0;
}
