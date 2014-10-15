//============================================================================
// Author      : Ahmed nasser
// Copyright   : codeFOrces :: http://codeforces.com/problemset/problem/157/A
// Description : Game Outcome
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
int main() {
	int n;
	scanf("%d", &n);
	int arr[n][n];
	FO(i,0,n)
		FO(e,0,n)
			scanf("%d", &arr[i][e]);
	int ret = 0;
	FO(i,0,n) {
		FO(e,0,n) {
			int col, row;
			col = row = 0;
			FO(s,0,n) {
				row += arr[i][s];
			}
			FO(s,0,n) {
				col += arr[s][e];
			}
			if (col > row) {
				ret++;
//				cout << i << " " << e << arr[i][e]<<endl;
			}
		}
	}
	cout << ret << endl;
}
