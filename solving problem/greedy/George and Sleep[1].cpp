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
string ret = "ABCDEF ";
bool vis[189][189];
int lvl = -1;
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	freopen("o.txt", "wt", stdout);
#endif

	string s1, s2;
	cin >> s1 >> s2;
	int t1 = 0, tmp, t2;
	string sub11 = s1.substr(0, 2), sub12 = s1.substr(3, SZ(s1));
	string sub21 = s2.substr(0, 2), sub22 = s2.substr(3, SZ(s1));
	stringstream ss;
	ss << sub11, ss >> tmp, t1 += (tmp * 60), ss.clear(), ss << sub12, ss
			>> tmp, t1 += tmp;
	ss.clear(), ss << sub21, ss >> tmp, t2 += (tmp * 60), ss.clear(), ss
			<< sub22, ss >> tmp, t2 += tmp;
	if (t1 < t2) {
		t1 += (24 * 60);
	}
	tmp = t1 - t2;
	t1 = tmp / 60;
	t2 = tmp % 60;
	if (t1 < 10) {
		cout << "0" << t1 << ":";
	} else
		cout << t1 << ":";
	if (t2 < 10)
		cout << "0" << t2;
	else
		cout << t2;
	cout << endl;
	return 0;
}
