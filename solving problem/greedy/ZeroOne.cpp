#include "bits/stdc++.h"
#include <functional>

using namespace std;

#define FO(i, a, x) for( i = a; i < (int)x; i++)
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
string sum(string x, string y) {
	string sm = "";
	int rem = 0;
	int i;
	FO(i , 0 , min(SZ(x) , SZ(y))) {
//		cout << sm << endl;
		if (x[i] == '1' && y[i] == '1') {
			if (rem == 1) {
				sm += '1';
			} else {
				sm += '0', rem = 1;
			}
		} else if (x[i] == '1' || y[i] == '1') {
			if (rem == 1) {
				sm += '0';
			} else {
				sm += '1', rem = 0;
			}
		} else {
			if (rem == 1) {
				sm += '1', rem = 0;
			} else {
				sm += '0';
			}
		}
	}
	if (SZ(x) == SZ(y)) {
		if (rem == 1)
			sm += '1';
		return sm;
	}
	string str = (SZ(x) > SZ(y)) ? x : y;
	while (i < SZ(str)) {
		if (rem == 1 && str[i] == '1') {
			sm += '0';
		} else if (rem == 1 && str[i] == '0') {
			sm += '1', rem = 0;
		} else
			sm += str[i];
		i++;
	}
	if (rem == 1)
		sm += '1';
	return sm;
}

int main() {
	int to = 1;
	cin >> n;
	string x, y;
	while (n--) {
		cin >> x >> y;
		while (x[0] == '0' && SZ(x) > 1) {
			x.erase(x.begin());
		}
		while (y[0] == '0' && SZ(y) > 1) {
			y.erase(y.begin());
		}
		reverse(all(x)), reverse(all(y));
		string str = sum(x, y);
		reverse(all(str));
		while (str[0] == '0' && SZ(str) > 1) {
			str.erase(str.begin());
		}
		if (n == 0)
			cout << to++ << " " << str;
		else
			cout << to++ << " " << str << endl;
	}
	return 0;
}
