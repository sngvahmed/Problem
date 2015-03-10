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
bool vis[10000];
int ret = 1 << 30;
bool primes[10000];
void initPrimes() {
	memset(primes, true, sizeof(primes));
	primes[0] = primes[1] = false;
	for (int i = 2; i <= 10000; i++) {
		if (primes[i]) {
			for (int j = 2; i * j <= 10000; j++)
				primes[i * j] = false;
		}
	}
}
int change_num(int indx, int num, int num_chng) {
	if (indx == 4 && num_chng == 0)
		return 1;
	int n[4], inx = 0, i = 0;
	while (num != 0) {
		(inx == indx - 1) ? n[i] = num_chng : n[i] = num % 10;
		num /= 10, i++, inx++;
	}
	int r = 3;
	while (i--) {
		num *= 10;
		num += n[r];
		r--;
	}
	return num;
}
int BFS(int num, int des) {
	queue<pair<int, int> > que;
	que.push(make_pair(num, 0));
	int lvl = 0;
	while (!que.empty()) {
		int sz = que.size();
		while (sz--) {
			pair<int, int> tmp = que.front();
			if (tmp.first == des)
				return tmp.second;
			que.pop();
			FO (i,1,5) {
				FO(e,0,10) {
					int nmb = change_num(i, tmp.first, e);
					if (vis[nmb] == 0 && primes[nmb]) {
						vis[nmb] = 1, que.push(make_pair(nmb, tmp.second + 1));
					}
				}
			}
		}
		lvl++;
	}
	return 0;
}
int main() {
	int co = 0;
	scanf("%d", &co);
	initPrimes();
	while (co--) {
		int n1, n2;
		scanf("%d%d", &n1, &n2);
		memset(vis, 0, sizeof vis);
//	REC(1033, 8179, 0);
		cout << BFS(n1, n2) << endl;
	}
	return 0;
}
