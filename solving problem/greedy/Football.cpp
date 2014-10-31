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
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		vector<int> num;
		int ret = 0;
		while (n--) {
			int tm1, tm2;
			scanf("%d%d", &tm1, &tm2);
			if (tm1 > tm2)
				ret += 3;
			else if (tm1 == tm2 && m > 0)
				m--, ret += 3;
			else if (tm1 == tm2 && m == 0)
				ret += 1;
			else
				num.push_back(abs(tm1 - tm2));
		}
		sort(num.begin(), num.end());
		int i = 0;
		while (m > 0 && i < SZ(num)) {
			if (num[i] < m)
				m = m - (num[i] + 1), ret += 3;
			else if (num[i] == m)
				m = 0, ret += 1;
			i++;
		}
		cout << ret << endl;
	}
	return 0;
}
