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
int di[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dj[] = { 1, -1, 0, 0, 1, -1, -1, 1 };

bool vis[189][189];
char arr[101][101];
double mem[101][101];
int n, m; // 7 5
double DP(int r, int i) {
	if (mem[r][i] == mem[r][i])
		return mem[r][i];
	double &tmp = mem[r][i] = 0;
	for (int rr = r; rr < n; rr++) {
		if (arr[rr][i] != '.' && arr[rr][i] != '*') {
			tmp += double(arr[rr][i] - '0');
			break;
		} else if (arr[rr][i] == '*') {
			tmp += DP(rr, i - 1) * 0.5;
			tmp += DP(rr, i + 1) * 0.5;
			break;
		}
	}
	return tmp;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	freopen("o.txt", "wt", stdout);
#endif
	int to;
	scanf("%d", &to);
	while (to--) {
		memset(mem, -1, sizeof mem);
		scanf("%d%d", &n, &m);
		double tt = 0;
		for (int i = 0; i < n; i++)
			for (int r = 0; r < m; r++)
				cin >> arr[i][r];

		for (int i = 0; i < m; i++) {
			cout << DP(0, i) << endl;
			tt = max(DP(0, i), tt);
		}
		cout << setprecision(6) << fixed << tt;
		printf("%.6Lf\n", tt);
	}
	return 0;
}
// @Copy Right To Ahmed Nasser
