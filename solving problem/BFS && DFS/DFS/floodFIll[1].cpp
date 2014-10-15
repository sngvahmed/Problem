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
int n, m, cnt = 0;
char arr[10000][10000];
bool vis[10000][10000];
bool validate(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == 0
			&& arr[i][j] != 'X';
}
void DFS(int i, int j) {
	FO(q,0,4) {
		if (validate(i + di[q], j + dj[q])) {
			vis[i + di[q]][j + dj[q]] = 1;
			DFS(i + di[q], dj[q] + j);
			cnt++;
		}
	}
}
int countMx() {
	int count = 0;
	FO(i,0,n) {
		FO(j,0,m) {
			cnt = 0;
			DFS(i, j);
			if (cnt > 0)
				count++;
		}
	}
	return count;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	freopen("o.txt", "wt", stdout);
#endif
	scanf("%d%d", &n, &m);
	FO(i,0,n)
		FO(j,0,m)
			cin >> arr[i][j];
	cout << countMx();
	return 0;
}
// @Copy Right To Ahmed Nasser
