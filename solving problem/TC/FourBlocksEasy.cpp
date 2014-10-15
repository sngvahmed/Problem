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
int di[] = { 0, 1, 1 }, dj[] = { 1, 0, 1 };
int n = 0, m = 0, co = 0;
bool vis[22][22][1 << 11];
char arr[22][22];

class FourBlocksEasy {
public:
	bool validate(int i, int j) {
		return (i >= 0 && j >= 0 && i < n && j < m) ? 1 : 0;
	}
	int maxScore(vector<string> grid) {
		bool vis[SZ(grid)][SZ(grid[0])];
		MMS(vis, 0);
		n = SZ(grid), m = SZ(grid[0]);
		int ret = 0;
		FO(i,0,SZ(grid)) {
			FO(j,0,SZ(grid[i])) {
				if (vis[i][j] == 0)
					if (grid[i][j] == '1')
						ret += 1, vis[i][j] = 1;
					else if (grid[i][j] == '.') {
						bool check = true;
						FO(r,0,3) {
							int DI = i + di[r], DJ = j + dj[r];
							if (!validate(DI, DJ) || grid[DI][DJ] != '.'
									|| vis[DI][DJ] == 1) {
								ret += 1, vis[i][j] = 1;
								check = false;
								break;
							}
						}
						if (check) {
							ret += 16;
							FO(r,0,3) {
								int DI = i + di[r], DJ = j + dj[r];
								if (validate(DI, DJ))
									vis[DI][DJ] = 1, vis[i][j] = 1;
							}

						}
					}
			}

		}
		return ret;
	}
};
