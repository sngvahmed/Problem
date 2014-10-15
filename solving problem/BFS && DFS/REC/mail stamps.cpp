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
map<int, int> vis;
map<int, vector<int> > arr;
vector<int> num, rt;
int n, m, co = 0;
bool validate(int i, int j) {
	return (i >= 0 && j >= 0 && i < n && j < m) ? 1 : 0;
}
void DFS(int i, int cont) {
	if (cont == SZ(num) - 1) {
		for (int r = SZ(rt) - 1; r >= 0; r--) {
			cout << rt[r] << " ";
		}
		co = 1;
		return;
	}
	FO(r,0,SZ(arr[i])) {
		if (vis[arr[i][r]] == 0) {
			vis[arr[i][r]] = 1, rt.push_back(arr[i][r]);
			DFS(arr[i][r], cont + 1);
			vis[arr[i][r]] = 0, rt.erase(rt.end() - 1);
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
//	freopen("o.txt", "wt", stdout);
#endif
	scanf("%d", &n);
	FO(i,0,n) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		if (vis[t1] == 0)
			num.push_back(t1), vis[t1] = 1;
		if (vis[t2] == 0)
			num.push_back(t2), vis[t2] = 1;
		arr[t1].push_back(t2), arr[t2].push_back(t1);
	}
	int r1 = 0;
	FO(i,0,SZ(num)) {
		if (SZ(arr[num[r1]]) > SZ(arr[num[i]])) {
			r1 = i;
		}
	}
	vis.clear(), rt.clear(), vis[num[r1]] = 1, rt.push_back(num[r1]);
	DFS(num[r1], 0);
	return 0;
}
