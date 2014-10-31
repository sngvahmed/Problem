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

#define FO(i, a, x) for(i = a; i < (int)x; i++)
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
string str = "ABCDEF ";
bool vis[189][189];
int lvl = 0;
void DP(string num, int r) {
	cout << r << " " << num << endl;
	int i;
	for (i = r; i < SZ(num) && SZ(num) > 2; i += 3) {
		int x = num[i] - '0', y = num[i + 1] - '0', z = num[i + 2] - '0';
		cout << x << " " << y << " " << z << " " << i << endl;
		if ((x + y) == 9 && (y + z) == 9) {
			string tmp = num;
			tmp[i] = '9', tmp.erase(tmp.begin() + i + 1), DP(tmp, i);
			tmp = num;
			tmp[i + 1] = '9', tmp.erase(tmp.begin() + i + 2), DP(tmp, i + 1);
			break;
		}
		if ((x + y) == 9) {
			string tmp = num;
			tmp[i] = '9', tmp.erase(tmp.begin() + i + 1), DP(tmp, i);
			break;
		}
		if ((z + y) == 9) {
			string tmp = num;
			tmp[i + 1] = '9', tmp.erase(tmp.begin() + i + 2), DP(tmp, i + 1);
			break;
		}
	}
	r = i;
	if (r > SZ(num)) {
		r -= 3;
		r = SZ(num) - 3;
		if (i == r) {
			string tmp = num;
			int x = num[i - r] - '0', y = num[i - r + 1] - '0';
			if ((x + y) == 9) {
				tmp[i] = '9', tmp.erase(tmp.begin() + i - r + 1), DP(tmp,
						SZ(num) - 1);
			}
		}
	}
	cout << i << " :: " << num << endl;
	if (i >= SZ(num) - 1) {
		cout << num << endl;
		lvl++;
	}
}
//272727272
int main() {
	string num;
	cin >> num;
//	DP(num, 0);
//	cout << lvl << endl;
	return 0;

}

