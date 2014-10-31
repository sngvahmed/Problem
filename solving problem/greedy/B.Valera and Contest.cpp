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

bool vis[189][189];
int main() {
//#ifndef ONLINE_JUDGE
//	freopen("test.in", "rt", stdin);
//	freopen("o.txt", "wt", stdout);
//#endif
//
//		output
//		2 3 2 3 3
	int n, k, l, u, sall, sk;
	scanf("%d%d%d%d%d%d", &n, &k, &l, &u, &sall, &sk);
	int arr[n];
	if (n == k) {
		int j = sall / n;
		for (int i = 0; i < n; i++)
			arr[i] = j;
		if (sall % n != 0) {
			int i = 0;
			j = sall % n;
			while (j--) {
				if (i == n)
					i = 0;
				arr[i]++;
				i++;
			}
		}
	} else {
		sall = sall - sk;
		int How = sk / k;
		FO(i,0,k) {
			arr[i] = How;
		}
		int m = sk % k;
		if (m != 0) {
			int i = 0;
			while (m--) {
				if (i == k)
					i = 0;
				arr[i]++;
				i++;
			}
		}

		int nn = n - k;
		How = sall / nn;
		FO(i,k,n) {
			arr[i] = How;
		}
		m = sall % nn;
		if (sall % nn != 0) {
			int i = k;
			while (m--) {
				if (i == n)
					i = k;
				arr[i]++;
				i++;
			}
		}
	}
	FO(i,0,n)
		cout << arr[i] << " ";
	return 0;
}
// @Copy Right To Ahmed Nasser
