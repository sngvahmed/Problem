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
class FOUR {
public:
	int x1, y1, x2, y2;
	FOUR(int x1, int y1, int x2, int y2) {
		this->x1 = x1, this->x2 = x2, this->y1 = y1, this->y2 = y2;
	}
	void OUT() {
		cout << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1
				<< endl;
	}
};
int find(vector<int> tmp, int rakm) {
	FO(i,0,SZ(tmp)) {
		if (tmp[i] == rakm)
			return i;
	}
	return -1;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	freopen("o.txt", "wt", stdout);
#endif
	map<int, int> viis;
	map<int, pair<int, int> > vis;
	int co, mx = 0;
	scanf("%d", &co);
	int arr[co];
	FO(i,0,co)
		scanf("%d", &arr[i]);
	vector<int> num, tmp;
	FO(i,0,co) {
		FO(r,0,arr[i]) {
			int tm;
			scanf("%d", &tm);
			vis[tm] = make_pair(i, r), num.push_back(tm), tmp.push_back(tm);
		}
	}
	vector<FOUR> ret;
	sort(num.begin(), num.end());
	int nu = 0;
	FO(i, 0, co) {
		FO(r,0,arr[i]) {
			if (num[nu] != tmp[nu]) {
				int tm = find(tmp, num[nu]), tr = num[nu];
				ret.push_back(FOUR(vis[tr].first, vis[tr].second, i, r));
				swap(vis[tmp[nu]], vis[tmp[tm]]);
				swap(tmp[nu], tmp[tm]);
				i = nu = r = -1, nu = 0;
				break;
			}
			nu++;
		}
	}
	cout << SZ(ret) << endl;
	FO(i,0,SZ(ret)) {
		ret[i].OUT();
	}
	return 0;
}
