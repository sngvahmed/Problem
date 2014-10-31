//Mar 2, 2014 :: All Roads Lead Where?.cpp
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
int n = 0, m = 0, co = 0;
string reach = "";
int arr[27][27];
void dfs(int from, int to, string comp, int vis) {
	if ((reach == "" || SZ(comp) <= SZ(reach)) && from == to) {
		reach = comp;
		return;
	}
	FO(i, 0, 27) {
		if (arr[from][i] && !(vis & 1 << i))
			dfs(i, to, comp + char(i + 'A'), (vis | 1 << i));
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	int to;
	scanf("%d", &to);
	while (to--) {
		scanf("%d%d", &n, &m);
		MMS(arr, 0);
		while (n--) {
			string tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			int x = tmp1[0] - 'A', y = tmp2[0] - 'A';
			arr[x][y] = arr[y][x] = 1;
		}
		while (m--) {
			reach = "";
			string tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			int x = tmp1[0] - 'A', y = tmp2[0] - 'A';
			string set = "";
			set += tmp1[0];
			dfs(x, y, set, 0);
			if (to == 0 && m == 0)
				cout << reach;
			else
				cout << reach << endl;
		}
		cout << endl;
	}
	return 0;
}
// COPY@SNGV :: Mar 2, 2014 :: sngv
