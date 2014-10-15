//============================================================================
// Author      : Ahmed nasser
// Copyright   : codeFOrces :: http://codeforces.com/problemset/problem/218/B
// Description : Airport
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
#include <numeric>
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
#define rall(x) x.rbegin(), x.rend()
#define MMS(x, v) memset(x, v, sizeof(x))
#define SQ(x) (x) * (x)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<string> vs;
typedef vector<int> vi;
int sumofnum(int x, int how) {
	int sum = 0;
	int e = 0;
	sum += x;
	while (x--) {
		if (how == e)
			return sum;
		e++;
		sum += x;
	}
	return sum;
}
int main() {
	/*4 3
	 2 1 1*/	int x, n, nmOFset = 0;
	scanf("%d %d", &x, &n);
	int arr[n];
	int arr2[n];
	FO(i,0,n) {
		cin >> arr[i];
	}
	int mx = 0, mn = 0;
	int r = x;
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
//		cout << r << " " << mn << endl;
		if (r == 0)
			break;
		if (r >= arr[i]) {
			r = r - arr[i];
			mn += sumofnum(arr[i], 100000);
		} else {
			mn += sumofnum(arr[i], r-1);
			r = 0;
		}
	}
	r = x;
	while (r != 0) {
		sort(arr, arr + n);
		mx += sumofnum(arr[n - 1], 0);
		arr[n - 1]--;
		r--;
	}
	cout << mx << " " << mn;
}

