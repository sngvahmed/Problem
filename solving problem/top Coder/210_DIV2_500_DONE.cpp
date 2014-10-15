//============================================================================
// Author      : Ahmed nasser
// Version     : 1
// Copyright   : 150
// Description : DONE
//============================================================================
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
class DrivingDirections {
public:
	vector<string> ret;
	char math1(string ss) {
		string s = "Start on ";
		string l = "Turn LEFT on ";
		string r = "Turn RIGHT on ";
		if (ss[5] == 'L') {
			string tp = s + ss.substr(l.size(), ss.size());
			ret.push_back(tp);
			return 'l';
		} else {
			string tp = s + ss.substr(r.size(), ss.size());
			ret.push_back(tp);
			return 'r';
		}
	}
	vector<string> reverse(vector<string> dr) {
		if (dr.size() == 1)
			return dr;
		string s = "Start on ";
		string l = "Turn LEFT on ";
		string r = "Turn RIGHT on ";
		char sss;
		int sz = dr.size();
		for (int i = sz - 1; i >= 0; i--) {
			if (i == sz - 1) {
				sss = math1(dr[i]);
			} else if (dr[i].substr(0, s.size()) == s) {
				if (dr[i + 1].substr(0, l.size()) == l) {
					ret.push_back(r + dr[i].substr(s.size(), dr[i].size()));
				} else if (dr[i + 1].substr(0, r.size()) == r) {
					ret.push_back(l + dr[i].substr(s.size(), dr[i].size()));
				}
			} else {
				if (dr[i + 1].substr(0, l.size()) == l) {
					if (dr[i].substr(0, l.size()) == l)
						ret.push_back(r + dr[i].substr(l.size(), dr[i].size()));
					else
						ret.push_back(r + dr[i].substr(r.size(), dr[i].size()));
				} else if (dr[i + 1].substr(0, r.size()) == r) {
					if (dr[i].substr(0, l.size()) == l)
						ret.push_back(l + dr[i].substr(l.size(), dr[i].size()));
					else
						ret.push_back(l + dr[i].substr(r.size(), dr[i].size()));
				}
			}
		}
		return ret;
	}
};
