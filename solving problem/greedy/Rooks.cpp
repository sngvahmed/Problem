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
char arr[101][101];
int ret[101][101];

bool find(vector<int> num, int sr) {
	FO(i,0,SZ(num))
		if (num[i] == sr)
			return 1;
	return 0;
}

int checkvector(vector<int> num) {
	int tp = 1;
	sort(num.begin(), num.end());
	while (find(num, tp)) {
		tp++;
	}
	return tp;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	freopen("o.txt", "wt", stdout);
#endif
	int co;
	scanf("%d", &co);
	while (co--) {
		int to;
		scanf("%d", &to);
		FO(i,0,to)
			FO(j,0,to)
				cin >> arr[i][j];
		memset(ret, 0, sizeof ret);
		int re = 0;
		FO(i,0,to) {
			for (int j = 0; j < to; j++) {
				if (arr[i][j] == '*' && ret[i][j] == 0) {
					vector<int> num;
					for (int r = 0; r < to; r++) {
						if (r != j && arr[i][r] == '*'
								&& !find(num, ret[i][r])) {
							num.push_back(ret[i][r]);
						}
					}
					for (int r = 0; r < to; r++) {
						if (r != i && arr[r][j] == '*'
								&& !find(num, ret[r][j])) {
							num.push_back(ret[r][j]);
						}
					}
					int tp = checkvector(num);
					ret[i][j] = tp;
					re = max(re, tp);
				} else {
					ret[i][j] = 0;
				}
			}
		}
		cout << re << endl;
		FO(i,0,to) {
			for (int j = 0; j < to; j++)
				if (j != to - 1) {
					if (arr[i][j] == '.')
						cout << 0 << " ";
					else
						cout << ret[i][j] << " ";
				} else {
					if (arr[i][j] == '.')
						cout << 0;
					else
						cout << ret[i][j];

				}
			cout << endl;
		}
	}
}
// @Copy Right To Ahmed Nasser
