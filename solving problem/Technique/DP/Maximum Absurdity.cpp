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
long long int arr[10000001];
int n, k;
vector<pair<long long, int> > v, l;
void DFS(long long int sum) {
	pair<int, int> ret;
	l.resize(v.size());
	l[SZ(l) - 1] = v[SZ(v) - 1];
	ROF(i,SZ(v)-2) {
		(v[i].first >= l[i + 1].first) ? l[i] = v[i] : l[i] = l[i + 1];
	}
//	FO(i,0,SZ(v))
//		cout << l[i].first << " " << l[i].second << endl;
	int r = 0;
	sum = 0;
	FO(i,k,SZ(v)) {
//		cout << v[i].second << " " << l[r].second << endl;
		if (l[i].first + v[r].first > sum) {
			ret = make_pair(min(l[i].second, v[r].second) + 1,
					max(v[r].second, l[i].second) + 1), sum = (v[r].first
					+ l[i].first);
		}
		r++;
	}
	cout << ret.first << " " << ret.second << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
//  freopen("o.txt", "wt", stdout);
#endif
	scanf("%d%d", &n, &k);
	int r = 0;
	long long sum = 0;
	FO(i,0,n) {
		cin >> arr[i];
		sum += arr[i];
		if (r + k - 1 == i)
			v.push_back(make_pair(sum, r)), sum -= arr[r], r++;
	}
	DFS(0);

	return 0;
}
