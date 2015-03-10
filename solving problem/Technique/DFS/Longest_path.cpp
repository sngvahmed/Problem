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
string ret = "ABCDEF ";
bool vis[10001];
int lvl = -1;
vector<vector<int> > v(10001);
int rt, mx;
void longestPath(int n, int l) {
	if (mx < l) {
		rt = n, mx = l;
	}
	FO(i,0,SZ(v[n])) {
		if (vis[v[n][i]] == 0) {
			vis[v[n][i]] = true;
			longestPath(v[n][i], l + 1);
		}
	}
}
void DFS(int n, int l, int ls) {
	if (mx < l) {
		rt = n, mx = l;
	}
	FO(i,0,SZ(v[n])) {
		if (ls != v[n][i]) {
			DFS(v[n][i], l + 1, n);
		}
	}
}
int main() {
	int n;
	cin >> n;
	int tmp1, tmp2;
	n--;
	while (n--) {
		cin >> tmp1 >> tmp2;
		v[tmp1].push_back(tmp2);
		v[tmp2].push_back(tmp1);
	}
	rt = mx = 0;
	memset(vis, 0, sizeof vis);
	DFS(tmp1, 0, -1);
	tmp1 = rt;
	rt = mx = 0;
	memset(vis, 0, sizeof vis);
	DFS(tmp1, 0, -1);
	cout << mx << endl;
	return 0;
}
