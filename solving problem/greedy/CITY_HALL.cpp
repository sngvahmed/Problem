//http://acm.tju.edu.cn/toj/showp1090.html
// city hall
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

#define N 4800
using namespace std;
bool EXIST(vector<int> x, int y) {
	FO(i,0,SZ(x))
		if (x[i] == y)
			return true;
	return false;
}
int main() {
	int n, y;
	scanf("%d %d", &n, &y);
	char wall[n][y];
	FO(i,0,n) {
		FO(e,0,y)
			cin >> wall[i][e];
	}
	map<int, int> ret;
	vector<int> sum;
	for (int i = 0; i < y; i++) {
		int si = 0;
		for (int e = 0; e < n; e++) {
			if (wall[e][i] == '0') {
				si++;
			}
			if (wall[e][i] == '1' && si > 0) {
				if (!EXIST(sum, si)) {
					sum.push_back(si);
				}
				ret[si]++;
				si = 0;
			}
		}
		if (si > 0) {
			if (!EXIST(sum, si)) {
				sum.push_back(si);
			}
			ret[si]++;
		}
	}
	sort(all(sum));
	FO(i,0,SZ(sum))
		cout << sum[i] << " " << ret[sum[i]] << endl;
}
