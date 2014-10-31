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
bool vis[189][189];
vector<vector<int> > num;
vector<int> cost;
int res;
map<int, pair<int, bool> > dp;
int di = 0, dj = 0;
int findTheBigest(int n) {
	int r = 0, mx = 0;
	FO(i,0,SZ(num[n])) {
		if (cost[num[n][i]] > mx) {
			r = num[n][i], mx = cost[num[n][i]];
		}
	}
	return r;
}
pair<int, int> DFS(int n, int value) {
	while (num[n].size() != 0) {
		n = findTheBigest(n);
		value += cost[n];
	}
	return make_pair(n, value);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	freopen("o.txt", "wt", stdout);
#endif
	int co;
	scanf("%d", &co);
	int to = 1;
	while (co--) {
		res = di = dj = 0;
		cost.clear(), num.clear();
		int n, m;
		scanf("%d%d", &n, &m);
		vector<int> any;
		FO(i,0,n) {
			int tmp;
			scanf("%d", &tmp);
			cost.push_back(tmp);
			num.push_back(any);
		}
		FO(j,0,m) {
			int tmp1, tmp2;
			scanf("%d%d", &tmp1, &tmp2);
			num[tmp1].push_back(tmp2);
		}
		pair<int, int> tmp = DFS(0, 0);
		cout << "Case " << to++ << ": " << tmp.second << " " << tmp.first
				<< endl;
	}
	return 0;
}
