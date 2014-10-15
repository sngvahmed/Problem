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
vector<pair<int, int> > var;
int main() {
	scanf("%d", &n);
	int X1, X2, Y1, Y2;
	cin >> X1 >> Y1 >> X2 >> Y2;
	pair<int, int> p1, p2;
	p1.F = X1, p1.S = Y1;
	p2.F = X2, p2.S = Y2;
	FO(i , 0 , n-1) {
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (x2 < p1.F || y2 < p1.S || y1 > p2.S || x1 > p2.F) {
			cout << 0 << endl;
			return 0;
		}
		if (x1 > p1.F && y1 > p1.S) {
			p1 = mp(x1, y1);
		} else if (y1 < p1.S && x1 > p1.F) {
			p1 = mp(x1, p1.S);
		} else if (x1 < p1.F && y1 > p1.S) {
			p1 = mp(p1.F, y1);
		}
		if (x2 < p2.F && y2 < p2.S) {
			p2 = mp(x2, y2);
		} else if (x2 < p2.F && y2 > p2.S) {
			p2 = mp(x2, p2.S);
		} else if (x2 > p2.F && y2 < p2.S) {
			p2 = mp(p2.F, y2);
		}
	}
	cout << p1.F << " " << p1.S << endl;
	cout << p2.F << " " << p2.S << endl;
	cout << abs(p1.F - p2.F) * abs(p2.S - p1.S) << endl;
	return 0;
}

