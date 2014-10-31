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
int SZ, rret = 0;
vector<pair<int, vector<int> > > num;
void Generate(int i, int ret, map<int, int> var) {
	if (i == SZ) {
		rret = max(ret, rret);
		return;
	}
	int mn = 1 << 30;
	Generate(i + 1, ret, var);
	FO(J,0,num[i].second.size()) {
		mn = min(var[num[i].second[J]], mn);
	}
	ret += mn * num[i].first;
	FO(J,0,num[i].second.size()) {
		var[num[i].second[J]] -= mn;
	}
	Generate(i + 1, ret, var);
}
int main() {
	int co;
	scanf("%d", &co);
	while (co--) {
		int n, m, tmp, rm, i = 1, ret = 0, cn = 0;
		rret = 0;
		scanf("%d%d", &n, &m);
		num.clear();
		while (n--) {
			scanf("%d", &tmp);
			vector<int> tm;
			while (tmp--) {
				scanf("%d", &rm);
				tm.push_back(rm);
			}
			scanf("%d", &rm);
			num.push_back(make_pair(rm, tm));
		}
		map<int, int> var;
		SZ = SZ(num);
		while (m--) {
			scanf("%d", &rm);
			var[i] = rm, i++;
		}
		sort(num.rbegin(), num.rend());
		Generate(0, 0, var);
		cout << rret << endl;
	}
	return 0;
}
