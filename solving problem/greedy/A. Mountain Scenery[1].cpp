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
bool vis[101];
string nm1, nm2, word;
bool check(string nm) {
	bool ch = true;
	FO(i,0,SZ(nm)) {
		bool ch1 = false;
		FO(e,0,SZ(word)) {
			if (vis[e] == 0 && nm[i] == word[e]) {
				ch1 = true;
				vis[e] = 1;
				break;
			}
		}
		if (!ch1) {
			ch = false;
			break;
		}
	}
	return ch;
}
int main() {

#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	freopen("o.txt", "wt", stdout);
#endif
	cin >> nm1 >> nm2 >> word;
	if ((SZ(nm1) + SZ(nm2)) != SZ(word)) {
		cout << "NO";
		return 0;
	}
	memset(vis, 0, sizeof word);
	if (!check(nm1) || !check(nm2)) {
		cout << "NO";
		return 0;
	}
	bool vs = true;
	FO(i,0,SZ(word)) {
		if (vis[i] == 0) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	;
	return 0;
}
// @Copy Right To Ahmed Nasser
