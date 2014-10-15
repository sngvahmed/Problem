//Mar 4, 2014 :: In Braille.cpp
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
int n = 0, m = 0, co = 0;
string str;
char s;
map<int, vector<string> > var;
map<int, string> vars;
bool validate(int i, int j) {
	return (i >= 0 && j >= 0 && i < n && j < m) ? 1 : 0;
}
void BUILD() {
	var[1].pb("*."), var[1].pb(".."), var[1].pb("..");
	var[2].pb("*."), var[2].pb("*."), var[2].pb("..");
	var[3].pb("**"), var[3].pb(".."), var[3].pb("..");
	var[4].pb("**"), var[4].pb(".*"), var[4].pb("..");
	var[5].pb("*."), var[5].pb(".*"), var[5].pb("..");
	var[6].pb("**"), var[6].pb("*."), var[6].pb("..");
	var[7].pb("**"), var[7].pb("**"), var[7].pb("..");
	var[8].pb("*."), var[8].pb("**"), var[8].pb("..");
	var[9].pb(".*"), var[9].pb("*."), var[9].pb("..");
	var[0].pb(".*"), var[0].pb("**"), var[0].pb("..");
	FO(i,0,10) {
		str = "";
		FO(e,0,SZ(var[i]))
			str += var[i][e];
		vars[i] = str;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	BUILD();
	while (scanf("%d", &n) && n) {
		scanf("%s", &s);
		if (s == 'S') {
			cin >> str;
			FO(j,0,3) {
				FO(i,0,SZ(str))
					if (i == SZ(str) - 1)
						cout << var[str[i] - '0'][j];
					else
						cout << var[str[i] - '0'][j] << " ";
				cout << endl;
			}
		} else {
			vs tmp(n);
			FO(i,0,3) {
				FO(j,0,SZ(tmp)) {
					cin >> str;
					tmp[j] += str;
				}
			}
			FO(i,0,SZ(tmp)) {
				FO(e,0,10) {
					if (tmp[i] == vars[e]) {
						cout << e;
						break;
					}
				}
			}
			cout << endl;
		}
	}
	return 0;
}
// COPY@SNGV :: Mar 4, 2014 :: sngv
