// May 20, 2014 , Bicycle Chain.cpp 
#include "bits/stdc++.h"
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
typedef pair<int, vi> vp;
map<int, vi> var;
int n, m;

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif

	scanf("%d", &n);
	vi a(n);
	FO(i , 0 , n)
		scanf("%d", &a[i]);

	scanf("%d", &m);
	set<int> num;
	map<int, int> var;
	int nm;

	FO(i,0,m) {
		scanf("%d", &nm);
		FO(e,0,n) {
			if (nm % a[e] == 0) {
				num.insert(nm / a[e]), var[nm / a[e]]++;
			}
		}
	}
	set<int>::iterator it;
	for (it = num.begin(); it != num.end(); it++) {
	}
	it--;
	cout << var[*it] << endl;

	return 0;
}
// CPY @SNGV
