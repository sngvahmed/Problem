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
int n, m;
int di[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dj[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
class BombSweeper {
public:
	bool valid(int i, int j) {
		return (i >= 0 && i < n && j >= 0 && j < m) ? 1 : 0;
	}
	double winPercentage(vector<string> board) {
		n = SZ(board), m = SZ(board[0]);
		int ret = 0, fl = 0;
		FO(i,0,SZ(board)) {
			FO(e,0,SZ(board[i])) {
				if (board[i][e] != 'B') {
					bool ch = 1;
					FO(r, 0 , 8) {
						if (valid(i + di[r], e + dj[r])
								&& board[i + di[r]][e + dj[r]] == 'B') {
							ch = false;
						}
					}
					if (ch) {
						ret++;
					}
				} else
					fl++;
			}
		}
		return double(ret) / double(ret + fl);
	}
};
