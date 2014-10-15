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
typedef vector<int> vi;
int di[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dj[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
int lvl = -1;
string ret = "ALLIZZWELL";
char arr[101][101];
int n, m, c;
map<pair<int, int>, bool> vv;
class izz {
public:
	int x, y, co;
	string num;
	map<pair<int, int>, bool> vIs;
	izz(int x, int y, int co, string num, map<pair<int, int>, bool> vIs) {
		this->co = co, this->x = x, this->y = y, this->num = num;
		this->vIs = vIs;
	}
};
bool validate(int DI, int DJ) {
	return (DI >= 0 && DI < n && DJ >= 0 && DJ < m) ? 1 : 0;
}
bool BFS(int ri, int rj) {
	queue<izz> que;
	map<pair<int, int>, bool> a;
	que.push(izz(ri, rj, 1, string("") + arr[ri][rj], a));
	que.front().vIs[make_pair(ri, rj)] = 1;
	while (!que.empty()) {
		int sz = que.size();
		while (sz--) {
			izz tmp = que.front();
			cout << tmp.num << endl;
			que.pop();
			if (tmp.num == ret)
				return 1;
			FO(i,0,8) {
				int DI = di[i] + tmp.x, DJ = dj[i] + tmp.y;
				tmp.vIs[make_pair(tmp.x, tmp.y)] = 1;
				if (tmp.num + arr[DI][DJ] == ret)
					return 1;
				if (validate(DI, DJ) && tmp.vIs[make_pair(DI, DJ)] == 0
						&& ret[tmp.co] == arr[DI][DJ]) {
					que.push(
							izz(DI, DJ, tmp.co + 1, tmp.num + arr[DI][DJ],
									tmp.vIs));
				}
			}
		}
	}
	return 0;
}

bool DFS(int i, int j, int co, string num, map<pair<int, int>, bool> vs) {
	if (num == ret) {
		c = 1;
		return true;
	}
	FO(r,0,8) {
		int DI = i + di[r], DJ = j + dj[r];
		if (validate(DI, DJ) && (arr[DI][DJ] == ret[co] || num == "")
				&& vs[make_pair(DI, DJ)] == 0) {
			vs[make_pair(DI, DJ)] = 1;
			DFS(DI, DJ, co + 1, num + arr[DI][DJ], vs);
			vs[make_pair(DI, DJ)] = 0;
		}
	}
	return 0;
}

int main() {
	int co;
	scanf("%d", &co);
	while (co--) {
		c = n = m = 0;
		vv.clear();
		scanf("%d%d", &n, &m);
		FO(i,0,n)
			FO(j,0,m)
				cin >> arr[i][j];
		bool ch = 0;
		FO(i,0,n) {
			FO(j,0,m)
				if (arr[i][j] == 'A'
						&& ((DFS(i, j, 1, string("") + 'A',
								map<pair<int, int>, bool>()) || c))) {
					ch = 1;
					break;
				}
			if (ch)
				break;
		}
		if (ch)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
