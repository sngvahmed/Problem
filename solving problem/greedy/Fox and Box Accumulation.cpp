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
int di[] = { 0, 0, 1, -1, 1, -1, 1, -1 }, dj[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
bool vis[100][100];
char arr[100][100];
int n, m;
bool validate(int i, int j) {
	return (i >= 0 && j >= 0 && i < n && j < m) ? 1 : 0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
//	freopen("o.txt", "wt", stdout);
#endif
	scanf("%d", &n);
	vector<vector<int> > num;
	vector<int> ret(n);
	FO(i,0,n)
		scanf("%d", &ret[i]);
	sort(ret.begin(), ret.end());
	int i = 0, tmp;
	vector<int> tm;
	tm.push_back(ret[0]);
	tmp = ret[0];
	num.push_back(tm);
	vector<int> mx;
	mx.push_back(1);
	ret.erase(ret.begin());
	while (ret.size()) {
		bool ch = 0;
		FO(r,0,SZ(num)) {
			if (mx[r] <= ret[i] && num[r][SZ(num[r]) - 1] <= ret[i])
				num[r].push_back(ret[i]), ch = 1, mx[r]++;
			if (ch)
				break;
		}
		if (ch == 0) {
			tm.clear();
			tm.push_back(ret[i]);
			num.push_back(tm), mx.push_back(1);
		}
		tmp = ret[i];
		ret.erase(ret.begin());
	}
//	FO(i,0,SZ(num)) {
//		FO(j,0,SZ(num[i]))
//			cout << num[i][j] << " ";
//		cout << endl;
//	}
	cout << SZ(num) << endl;
	return 0;
}
