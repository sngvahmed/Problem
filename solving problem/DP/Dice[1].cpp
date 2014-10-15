//http://acm.tju.edu.cn/toj/showp3486.html
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
int dice[] = { 1, 2, 3, 4, 5, 6 };
int ho = 0;
bool chmem[101][601];
double mem[101][601];
int des, co;
double DPtmp(int r, int res) {
	if (r == co)
		return des == res;
	if (chmem[r][res] == 1)
		return mem[r][res];
	double &ret = mem[r][res] = 0;
	chmem[r][res] = 1;
	for (int i = 0; i < 6; i++) {
		ret += DPtmp(r + 1, res + dice[i]);
	}
	return mem[r][res] = (ret) / 6;
}
double DP(int r, int res) {
	if (r == co)
		return des == res;
	double &tmp = mem[r][res];
	if (tmp == tmp)
		return tmp;
	double &ret = mem[r][res] = 0;
	chmem[r][res] = 1;
	for (int i = 0; i < 6; i++) {
		ret += DP(r + 1, res + dice[i]);
	}
	return mem[r][res] = (ret) / 6;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	freopen("o.txt", "wt", stdout);
#endif
	int to;
	scanf("%d", &to);
	while (to--) {
		cin >> co >> des;
		memset(chmem, 0, sizeof chmem);
		memset(mem, -1, sizeof mem);
//		printf("%.2Lf\n", DP(co, des));
		cout << setprecision(2) << fixed << double(DP(0, 0)) << endl;
	}
	return 0;
}
// @Copy Right To Ahmed Nasser
