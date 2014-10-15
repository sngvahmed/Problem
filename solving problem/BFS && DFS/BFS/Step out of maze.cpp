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
bool vis[101][101];
int arr[101][101], n, m;
bool validate(int i, int j) {
	return (i < 0 || i >= n || j < 0 || j >= m) ? 0 : 1;
}
class maza {
public:
	int x, y;
	string kelma;
	maza(int x, int y, string kelma) {
		this->x = x, this->kelma = kelma, this->y = y;
	}
};
string BFS(int t1, int t2) {
	queue<maza> que;
	que.push(maza(t1, t2, ""));
	while (!que.empty()) {
		int sz = que.size();
		while (sz--) {
			maza maz = que.front();
			que.pop();
			FO(i,0,4) {
				int DI = maz.x + di[i], DJ = maz.y + dj[i];
				char cr;
				if (i == 0)
					cr = 'R';
				else if (i == 1)
					cr = 'L';
				else if (i == 2)
					cr = 'D';
				else
					cr = 'U';
				if (validate(DI, DJ) && vis[DI][DJ] == 0 && arr[DI][DJ] == 0) {
					vis[DI][DJ] = 1;
					que.push(maza(DI, DJ, maz.kelma + cr));
				} else if (!validate(DI, DJ)) {
					return maz.kelma + cr;
				}
			}
		}
	}
	return "";
}
int main() {
	int co;
	scanf("%d", &co);
	while (co--) {
		memset(vis, 0, sizeof vis);
		scanf("%d%d", &n, &m);
		FO(i,0,n)
			FO(j,0,m)
				scanf("%d", &arr[i][j]);
		int tmp1, tmp2;
		scanf("%d%d", &tmp1, &tmp2);
		string tmp = BFS(tmp1 - 1, tmp2 - 1);
		FO(i,0,SZ(tmp))if(i==SZ(tmp)-1)cout << tmp[i];else cout << tmp[i] << " ";
		cout << endl;
	}
	return 0;
}
