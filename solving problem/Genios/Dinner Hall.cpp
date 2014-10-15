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
int n;
class Hall {
public:
	int time;
	char who;
	Hall(int time, char who) {
		this->time = time, this->who = who;
	}
};
bool compare(const Hall& a, const Hall& b) {
	return a.time < b.time;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	while (scanf("%d", &n) && n) {
		vector<Hall> v;
		int un, in, out;
		un = in = out = 0;
		FO(i,0,n)
		{
			char d;
			int a, b, c;
			cin >> a >> d >> b >> d >> c >> d;
			v.pb(Hall((a * 60 * 60) + (b * 60) + c, d));
			if (d == 'X')
				out++;
			if (d == 'E')
				in++;
			if (d == '?')
				un++;
		}
		sort(v.begin(), v.end(), compare);
		int mxIN = un - (in - out), ret = 0, len = 0;
		mxIN /= 2;
		FO(i, 0, SZ(v))
		{
			if (v[i].who == 'E') {
				len++;
			} else if (v[i].who == 'X') {
				len--;
			} else {
				if (mxIN)
					len++, mxIN--;
				else
					len--;
			}
			ret = max(ret, len);
		}
		cout << ret << endl;
	}
	return 0;
}
// COPY@SNGV
