// Mar 19, 2014 A.cpp
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
char arr[301][301];
bool validate(int i, int j) {
	return (i >= 0 && j >= 0 && i < n && j < m) ? 1 : 0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	scanf("%d", &n);
	FO(i,0,n)
		FO(j,0,n)
			cin >> arr[i][j];
	char tmp = arr[0][0];
	bool vs[301][301];
	MMS(vs, 0);
	FO(i,0,n) {
		if (arr[i][i] != tmp) {
			cout << "NO" << endl;
			return 0;
		}
		vs[i][i] = 1;
	}
	int r = 0;
	for (int i = n - 1; i >= 0; i--, r++) {
		if (arr[r][i] != tmp) {
			cout << "NO" << endl;
			return 0;
		}
		vs[r][i] = 1;
	}
//	if (tmp == arr[0][1]) {
//		cout << "NO" << endl;
//		return 0;
//	}
	tmp = arr[0][1];
	FO(i,0,n) {
		FO(j,0,n) {
			if (vs[i][j] == 0 && arr[i][j] != tmp) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES" << endl;
}
//@CPY::SNGV
