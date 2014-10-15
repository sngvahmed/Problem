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

bool vis[189][189];
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	freopen("o.txt", "wt", stdout);
#endif
	int co;
	scanf("%d", &co);
	map<int, pair<int, int> > num;
	num[1] = make_pair(0, 0);
	num[2] = make_pair(0, 0);
	while (co--) {
		int tmp1, tmp2, tmp3;
		scanf("%d%d%d", &tmp1, &tmp2, &tmp3);
		num[tmp1].first += tmp2;
		num[tmp1].second += tmp3;
	}
	if (num[1].first >= (num[1].first + num[1].second) / 2)
		cout << "LIVE";
	else
		cout << "DEAD";
	cout << endl;
	if (num[2].first >= (num[2].first + num[2].second) / 2)
		cout << "LIVE";
	else
		cout << "DEAD";

	return 0;
}
// @Copy Right To Ahmed Nasser
