//http://codeforces.com/contest/29/problem/A
// Spit Problem
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
int arr1[10000], arr2[10000];
bool mad(int x) {
	FO(i,0,x) {
		FO(r,i+1,x) {
			int si = arr1[i] + arr2[i];
			int sj = arr1[r] + arr2[r];
			if (si == arr1[r] && sj == arr1[i]) {
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	int x;
	cin >> x;
	FO(i,0,x)
		scanf("%d%d", &arr1[i], &arr2[i]);
	bool xx = mad(x);
	if (!xx)
		cout << "NO";
	else
		cout << "YES";
}
