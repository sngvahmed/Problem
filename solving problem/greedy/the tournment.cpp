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
int n = 0, m = 0, co = 1 << 30;
bool vis[200001];
vector<pair<int, int> > var;
bool validate(int i, int j) {
	return (i >= 0 && j >= 0 && i < n && j < m) ? 1 : 0;
}
int CH(int po) {
	int re = SZ(var) + 1;
	FO(i,0,n)
	{
		if (var[i].first < po) {
			re--;
		} else if (var[i].first == po && vis[i] == 1)
			re--;
	}
	return re;
}
void BF(int i, int sum, int rm) {
	if (i == SZ(var)) {
		if (CH(rm) <= m) {
			co = min(co, sum);
		}
		return;
	}
	var[i].first = var[i].first + 1, vis[i] = 0;
	BF(i + 1, sum, rm);
	vis[i] = 1, var[i].first = var[i].first - 1;
	BF(i + 1, sum + var[i].second, rm + 1);
	vis[i] = 0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
//	freopen("o.txt", "wt", stdout);
#endif
	scanf("%d%d", &n, &m);
	memset(vis, 0, sizeof vis);
	FO(i,0,n)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		var.pb(mp(tmp1, tmp2));
	}
	BF(0, 0, 0);
	if (co == 1 << 30)
		cout << -1 << endl;
	else
		cout << co << endl;
	return 0;
}
// COPY@SNGV
