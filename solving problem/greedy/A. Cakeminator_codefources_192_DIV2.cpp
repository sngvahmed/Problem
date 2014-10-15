//============================================================================
// Author      : Ahmed nasser
// Version     : 1
// Copyright   : A. Cakeminator
// Description : http://codeforces.com/contest/330/problem/A
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
int main() {
	int x, y, sum = 0;
	cin >> x >> y;
	char arr[x][y];
	FO(i,0,x)
		FO(n,0,y)
			cin >> arr[i][n];
	FO(i,0,x) {
		bool l = true;
		FO(n,0,y) {
			if (arr[i][n] == 'S') {
				l = false;
				break;
			}
		}
		if (l == true) {
			FO(n,0,y) {
				if (arr[i][n] == '.')
					sum++;
				arr[i][n] = 'r';
			}
		}
	}
	FO(i,0,y) {
		bool l = true;
		FO(n,0,x) {
			if (arr[n][i] == 'S') {
				l = false;
				break;
			}
		}
		if (l == true) {
			FO(n,0,x) {
				if (arr[n][i] == '.')
					sum++;
				arr[n][i] = 'r';
			}
		}
	}
	cout << sum;
	return 0;
}
