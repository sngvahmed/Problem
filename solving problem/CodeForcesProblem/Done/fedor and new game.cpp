// @Oct 12, 2014
// @CPY sngv ..... fedor and new game.cpp 
#include "bits/stdc++.h"
#include <functional>
#include <ext/numeric> // for power long long 
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
typedef pair<int, vi> pi;
typedef pair<int, int> vp;
typedef pair<int, pair<int, int> > Hamada;

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif

			int n,m,k;
			scanf("%d%d%d", &n, &m, &k);
			vi var;
			FO(i , 0 , m+1)
			{
				int tmp;
				cin >> tmp;
				var.pb(tmp);
			}
			int count = 0;
			for(int i = 0; i < SZ(var)-1; i ++) {
				count += (__builtin_popcount(var[i] ^ var[SZ(var)-1]) <=k);}
			cout << count << endl;
			return 0;
		}
