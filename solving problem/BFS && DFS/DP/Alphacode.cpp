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
string str;
int mem[5001];
bool check(string ch) {
	stringstream ss;
	int bol;
	ss << ch, ss >> bol;
	return (bol >= 1 && bol <= 26) ? 1 : 0;
}
int DP(int i) {
	if (i == SZ(str))  return 1;
	if (str[i] == '0') return 0;
	if (mem[i] != -1)  return mem[i];
	int &ret = mem[i] = 0;
	ret += DP(i + 1);
	string tm = "";
	if (i + 1 < SZ(str)) {
		tm += str[i], tm += str[i + 1];
		if (check(tm))
			ret += DP(i + 2);
	}
	return ret;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	while (cin >> str && str[0] != '0') {
		MMS(mem, -1);
		cout << DP(0) << endl;
	}
	return 0;
}
// COPY@SNGV

