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
bool vis[1001][1001];
int lvl = -1;
class ExerciseMachine {
public:
	int GetTime(string time) {
		string t1 = time.substr(0, 2), t2 = time.substr(3, 2), t3 = time.substr(
				6, 2);
		int ret = 0, tmp;
		stringstream ss;
		ss << t1, tmp = 0, ss >> tmp, ret += (tmp * 3600), ss.clear();
		// ******
		ss << t2, tmp = 0, ss >> tmp, ret += (tmp * 60), ss.clear();
		// ******
		ss << t3, tmp = 0, ss >> tmp, ret += tmp;
		cout << t1 << " " << t2 << " " << t3 << endl;
		return ret;
	}
	int getPercentages(string time) {
		int tm = GetTime(time), ret = 0;
		for (int i = 1; i < 100;) {
			int r = (tm * i) / 100;
			(tm * i == r * 100) ? ret++, i++ : i++;
		}
		return ret;
	}
};
