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
int n;
vector<vector<int> > num(1000001);
bool vis[1000001];
bool BFS(int i, int r) {
	vis[i] = 1;
	queue<int> que;
	que.push(i);
	map<int, int> su;
	su[i] = r;
	while (!que.empty()) {
		int sz = que.size();
		while (sz--) {
			int Tmp = que.front();
			que.pop();
			FO(i, 0, SZ(num[Tmp])) {
				if (su[num[Tmp][i]] == 0) {
					que.push(num[Tmp][i]);
					vis[num[Tmp][i]] = 1;
					(su[Tmp] == 1) ? su[num[Tmp][i]] = 2 : su[num[Tmp][i]] = 1;
				} else if (su[Tmp] == su[num[Tmp][i]]) {
					return 0;
				}
			}
		}
	}
	return 1;
}
bool Generate(int i) {
	return BFS(i, 1) || BFS(i, 2);
}
int main() {
	int co = 0;
	scanf("%d", &co);
	int qq = 1;
	while (co--) {
		memset(vis, 0, sizeof vis);
		num.clear();
		num.resize(1000001);
		int r1, r2;
		r1 = r2 = n = 0;
		scanf("%d%d", &r1, &r2);
		n = r2;
		FO(i,0,r2) {
			int tmp1, tmp2;
			scanf("%d%d", &tmp1, &tmp2);
			num[tmp1 - 1].push_back(tmp2 - 1), num[tmp2 - 1].push_back(tmp1 - 1);
		}
		bool ch = false;
		FO(i,0,r1) {
			if (vis[i] == 0 && !Generate(i)) {
				ch = true;
				break;
			}
		}
		cout << "Scenario #" << qq++ << ":" << endl;
		if (!ch)
			cout << "No suspicious bugs found!" << endl;
		else
			cout << "Suspicious bugs found!" << endl;
	}
	return 0;
}
