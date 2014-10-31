// Mar 9, 2014 ErdosNumber.cpp
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
int di[] = { 0, 0, 1, -1, 1, -1, 1, -1 }, dj[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
int n = 0, m = 0, co = 0;
vector<pair<string, vector<string> > > var;
string str;
class ErdosNumber {
public:
	vector<string> calculateNumbers(vector<string> publications) {
		map<string, set<string> > vec;
		set<string> que;
		map<string, int> vis;
		FO(i,0,publications.size()) {
			stringstream ss;
			ss << publications[i];
			string tm, tmp;
			ss >> tm;
			que.insert(tm);
			while (!ss.eof()) {
				ss >> tmp;
				vec[tm].insert(tmp);
				que.insert(tmp);
			}
		}
		for (set<string>::iterator it = vec["A"].begin(); it != vec["A"].end();
				it++)
			cout << *it << endl;

		queue<string> Q;
		Q.push("ERDOS");
		int lvl = 0;
		while (!Q.empty()) {
			int sz = SZ(Q);
			while (sz--) {
				string tmp = Q.front();
				Q.pop();
				for (set<string>::iterator it = vec[tmp].begin();
						it != vec[tmp].end(); it++) {
					if (vis[*it] == 0) {
						Q.push(*it), vis[*it] = lvl + 1;
					}
				}
			}
			lvl++;
		}
		publications.clear();
		for (set<string>::iterator it = que.begin(); it != que.end(); it++) {
			if (*it == "ERDOS") {
				publications.push_back(*it + " 0");
			} else if (vis[*it] != 0) {
				stringstream ss;
				ss << vis[*it];
				string tmp;
				ss >> tmp;
				publications.push_back(*it + " " + tmp);
			} else
				publications.push_back(*it);
		}
		return publications;
	}
};
//@CPY::SNGV
