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
int month[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
class Birthday {
public:
	string getNext(string date, vector<string> birthdays) {
		pair<int, int> dt;
		dt.first = int(date[0] - '0') * 10 + int(date[1] - '0');
		dt.second = int(date[3] - '0') * 10 + int(date[4] - '0');
		pair<int, int> ret;
		ret.first = ret.second = 1000;
		int rettm = 1000000000;
		FO(i,0,SZ(birthdays)) {
			cout << i << endl;
			int dt1 = int(birthdays[i][0] - '0') * 10
					+ int(birthdays[i][1] - '0'), dt2 = int(
					birthdays[i][3] - '0') * 10 + int(birthdays[i][4] - '0'),
					tmp = 0, r = dt.first;
			if (dt1 == dt.first && dt2 == dt.second)
				tmp = 0;
			else if (dt1 == dt.first && dt2 > dt.second) {
				tmp += dt2 - dt.second;
			} else {
				tmp = dt1 - dt.first;
				if (tmp <= 0)
					tmp += 12;
				tmp = tmp * 30, tmp += dt2;
			}
			if (rettm > tmp)
				ret.first = dt1, ret.second = dt2, rettm = tmp;

		}
		string t1, t2;
		stringstream ss;
		ss << ret.first, ss >> t1;
		ss.clear();
		ss << ret.second, ss >> t2;
		if (t1.size() == 1)
			t1 = "0" + t1;
		if (t2.size() == 1)
			t2 = "0" + t2;
		return t1 + "/" + t2;
	}
};
