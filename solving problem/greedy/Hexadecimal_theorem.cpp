#include "bits/stdc++.h"
#include <functional>

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
int n, m;
vi var;
map<long, int> tmp;
void BuildFib(int i) {
	var.pb(tmp[i - 1]);
	if (tmp[i - 1] >= 1000000000)
		return;
	tmp[i] = tmp[i - 1] + tmp[i - 2];
	BuildFib(i + 1);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	var.pb(0), tmp[0] = 0, tmp[1] = 1, BuildFib(2);
	cin >> n;
	FO( i , 0 , SZ(var)) {
		FO( j , i , SZ(var)) {
			FO( k , 0 , SZ(var)) {
				if (var[i] + var[j] + var[k] == n) {
					cout << var[i] << " " << var[j] << " " << var[k] << endl;
					return 0;
				}
			}
		}
	}
	cout << "I'm too stupid to solve this problem" << endl;
	return 0;
}
