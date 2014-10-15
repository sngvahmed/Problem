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
vector<vector<pair<int, int> > > arr;
bool vis[2002];
int mx = 0;
int gl = 0;
void DFS(int node, int value) {
	if (vis[node]++)
		return;
	if (value > gl)
		mx = node, gl = value;
	for (int i = 0; i < SZ(arr[node]); i++)
		DFS(arr[node][i].first, value + arr[node][i].second);
}
int main() {
	int co;
	scanf("%d", &co);
	while (co--) {
		int to;
		scanf("%d", &to);
		arr.clear();
		arr.resize(to + 1);
		to--;
		mx = 0, gl = 0;
		while (to--) {
			int n, m, cost;
			scanf("%d%d%d", &n, &m, &cost);
			arr[n - 1].push_back(make_pair(m - 1, cost));
			arr[m - 1].push_back(make_pair(n - 1, cost));
		}
		memset(vis, 0, sizeof vis);
		DFS(0, 0);
		gl = 0;
		memset(vis, 0, sizeof vis);
		DFS(mx, 0);
		cout << gl << endl;
	}
	return 0;
}
// @Copy Right To Ahmed Nasser
