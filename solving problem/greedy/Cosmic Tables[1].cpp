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
bool vis[189][189];
int lvl = -1;
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	freopen("o.txt", "wt", stdout);
#endif
	int n, m, r;
	scanf("%d%d%d", &n, &m, &r);
	int arr[1010][1010], cm[1010], rw[1010];
	FO(i,0,n)
		FO(j,0,m)
			scanf("%d", &arr[i][j]);
	FO(i,0,m)
		cm[i] = i;
	FO(i,0,n)
		rw[i] = i;
	while (r--) {
		int tmp1, tmp2, sw;
		char tmp;
		cin >> tmp >> tmp1 >> tmp2;
		tmp1--, tmp2--;
		if (tmp == 'c') {
			sw = cm[tmp1], cm[tmp1] = cm[tmp2], cm[tmp2] = sw;
		}
		if (tmp == 'r') {
			sw = rw[tmp1], rw[tmp1] = rw[tmp2], rw[tmp2] = sw;
		}
		if (tmp == 'g')
			cout << arr[rw[tmp1]][cm[tmp2]] << endl;
	}
}
