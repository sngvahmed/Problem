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
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
//	freopen("o.txt", "wt", stdout);
#endif
	int n, v, m;
	cin >> n >> m >> v;
	int l = 1;
	int r = (n - 2);
	int mxE = ((r * (r - 1) / 2) + (l * (l - 1) / 2) + 1 + r);
	int mnE = n - 1;
	if (m < mnE || m > mxE) {
		cout << "-1" << endl;
	} else {
		vector<int> lf, rg, nm;
		int i = 0;
		FO(i,1,n+1) {
			if (i != v) {
				nm.push_back(i);
			}
		}
		for (int i = 0; i < nm.size(); i++) {
			if (m == 0)
				return 0;
			cout << nm[i] << " " << v << endl;
			m--;
		}
		for (int i = 0; i < nm.size() - 1; i++) {
			for (int j = i + 1; j < nm.size() - 1; j++) {
				if (m == 0)
					return 0;
				cout << nm[i] << " " << nm[j] << endl;
				m--;
			}
		}

	}
	return 0;
}
