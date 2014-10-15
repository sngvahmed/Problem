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
char arr[101][101];
bool vis[101][101];
int n, m;
void REC(int i, int j) {
	if (vis[i][j] == 1 || arr[i][j] == '*')
		return;
	vis[i][j] = 1;
	for (int r = 0; r < 8; r++) {
		if ((i + di[r]) >= 0 && (i + di[r]) < n && (j + dj[r]) >= 0
				&& (j + dj[r]) < m) {
			REC(i + di[r], j + dj[r]);
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	freopen("o.txt", "wt", stdout);
#endif
	while (scanf("%d%d", &n, &m) && n != 0 && m != 0) {
		for (int i = 0; i < n; i++)
			scanf("%s", arr[i]);
		memset(vis, 0, sizeof vis);
		int tot = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == '@' && vis[i][j] == 0) {
					REC(i, j);
					tot++;
				}
			}
		}
		cout << tot << endl;
	}
	return 0;
}
// @Copy Right To Ahmed Nasser
