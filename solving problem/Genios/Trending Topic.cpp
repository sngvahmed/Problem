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
map<string, int> num;
set<string> ret;
vector<pair<set<string>, map<string, int> > > arr;
void Generate() {
	for (set<string>::iterator it = arr[0].first.begin();
			it != arr[0].first.end(); it++) {
		num[*it] -= arr[0].second[*it];
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	freopen("o.txt", "wt", stdout);
#endif
	string x;
	while (cin >> x) {
		if (x == "<text>") {
			set<string> tmp1;
			map<string, int> tmp2;
			while (cin >> x && x != "</text>") {
				if (SZ(x) > 3) {
					ret.insert(x), num[x]++, tmp1.insert(x), tmp2[x]++;
				}
			}
			arr.push_back(make_pair(tmp1, tmp2));
			if (arr.size() > 7)
				Generate(), arr.erase(arr.begin());
		} else {
			int top, co = 0;
			cin >> top >> x;
			map<int, vector<string> > tmp;
			for (set<string>::iterator it = ret.begin(); it != ret.end();
					it++) {
				if (num[*it] != 0)
					co = max(co, num[*it]), tmp[num[*it]].push_back(*it);
			}
			cout << "<top " << top << ">" << endl;
			int cont = 0;
			co++;
			while (co-- && cont < top) {
				sort(tmp[co].begin(), tmp[co].end());
				FO(i,0,SZ(tmp[co])) {
					cont++;
					cout << tmp[co][i] << " " << co << endl;
				}
			}
			cout << "</top>" << endl;
		}
	}
	return 0;
}
