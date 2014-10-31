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
vector<string> bd;
map<string, int> wd;
string withoutSign(string tmp) {
	string num = "";
	FO(i,0,SZ(tmp)) {
		if (tmp[i] >= 'a' && tmp[i] <= 'z') {
			num += tmp[i];
		} else {
			tmp[i] += 32;
			if (tmp[i] >= 'a' && tmp[i] <= 'z') {
				num += tmp[i];
			}
		}
	}
	return num;
}
void Dirty_fun() {
	string tmp1 = bd[0], tmp2 = bd[0];
	tmp1 += bd[1], tmp2 += bd[2];
	tmp2 += bd[1], tmp1 += bd[2];
	wd[tmp1] = 1, wd[tmp2] = 1;
	tmp1 = bd[1], tmp2 = bd[1];
	tmp1 += bd[0], tmp2 += bd[2];
	tmp2 += bd[0], tmp1 += bd[2];
	wd[tmp1] = 1, wd[tmp2] = 1;
	tmp1 = bd[2], tmp2 = bd[2];
	tmp1 += bd[0], tmp2 += bd[1];
	tmp2 += bd[0], tmp1 += bd[1];
	wd[tmp1] = 1, wd[tmp2] = 1;
}
int main() {
	FO(i,0,3) {
		string tmp;
		cin >> tmp;
		tmp = withoutSign(tmp);
		wd[tmp] = 1;
		bd.push_back(tmp);
	}
	int co = 0;
	cin >> co;
	Dirty_fun();
	while (co--) {
		string tmp;
		cin >> tmp;
		tmp = withoutSign(tmp);
		if (wd[tmp])
			cout << "ACC";
		else
			cout << "WA";
		cout << endl;
	}
	return 0;
}
