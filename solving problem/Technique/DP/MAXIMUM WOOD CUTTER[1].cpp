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
int DP[210][210][2]; // 1-> left 2->right
char vis[210][210];
int n, m;
int DPP(int i, int j, int dic) {
//	cout << i << " " << j << " " << dic << endl;
	if (vis[i][j] == '#')
		return 0;
	if (DP[i][j][dic] != -1) {
		return DP[i][j][dic];
	}
	int &res = DP[i][j][dic] = 0;
	//************************************
	if (i < n && j < m && i >= 0 && j >= 0)
		if (dic == 1) {
			if (vis[i][j] == 'T')
				res += max(DPP(i, j - 1, 1), DPP(i + 1, j, 2)) + 1;
			else
				res += max(DPP(i, j - 1, 1), DPP(i + 1, j, 2));
		} else {
			if (vis[i][j] == 'T')
				res += max(DPP(i, j + 1, 2), DPP(i + 1, j, 1)) + 1;
			else
				res += max(DPP(i, j + 1, 2), DPP(i + 1, j, 1));
		}
	//************************************
	return res;
}
int main() {
#ifndef ONLINE_JUDGE
//	freopen("test.in", "rt", stdin);
//	freopen("o.txt", "wt", stdout);
#endif
	int to;
	scanf("%d", &to);
	while (to--) {
		memset(DP, -1, sizeof DP);
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%s", vis[i]);
		}
		cout << DPP(0, 0, 2) << endl;
	}
	return 0;
}
// @Copy Right To Ahmed Nasser
