//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlin//ejudge&Itemid=8&page=show_problem&problem=1890
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
map<char, bool> m;
map<pair<char, int>, bool> visbool;
map<pair<char, int>, int> visint;
map<char, int> siz;
bool ch1(string str) {
	int i = str.size() - 1;
	char f;
	string sub;
	while (str[i] == ']') {
		i--;
	}
	int r = i;
	while (str[r] != '[') {
		r--;
	}
	sub = str.substr(r + 1, i - r);
	r--;
	f = str[r];
	i = 2;
	stringstream ss;
	ss << sub;
	int ret;
	ss >> ret;
	if (r == 0) {
		if (m[f] == true)
			return 0;
		m[f] = 1;
		siz[f] = ret;
		return 1;
	}
	while (true) {
		if (i == r || r < i)
			break;
		if (m[f] == false || ret >= siz[f] || visbool[make_pair(f, ret)] == 0) {
			return 0;
		}
		r -= 2;
		f = str[r];
		ret = visint[make_pair(f, ret)];
	}
	r -= 2;
	f = str[r];
	if (m[f] == true)
		return 0;
	m[f] = 1;
	siz[f] = ret;
	return 1;
}
int kema(string str) {
	if (SZ(str) == 1 || str[1] != '[') {
		stringstream ss;
		ss << str;
		int rett;
		ss >> rett;
		return rett;
	}
	int i = str.size() - 1;
	char f;
	string sub;
	while (str[i] == ']') {
		i--;
	}
	int r = i;
	while (str[r] != '[') {
		r--;
	}
	sub = str.substr(r + 1, i - r);
	r--;
	f = str[r];
	i = 2;
	stringstream ss;
	ss << sub;
	int ret;
	ss >> ret;
	if (r == 0) {
		if (m[f] == false || ret >= siz[f] || visbool[make_pair(f, ret)] == 0) {
			return -1;
		} else
			return visint[make_pair(f, ret)];
	}
	if (m[f] == false || ret >= siz[f] || visbool[make_pair(f, ret)] == 0) {
		return -1;
	}
	while (true) {
		 if(r <= 0)break;
		if (i == r || r < i)
            if (m[f] == false || ret >= siz[f]) {
                return 0;
            }
		r -= 2;
        ret = visint[make_pair(f, ret)];
		f = str[r];
	}
	if (m[f] == false || ret >= siz[f] || visbool[make_pair(f, ret)] == 0) {
		return -1;
	} else
		return visint[make_pair(f, ret)];
}
bool kema2(int w, string str) {
	int i = str.size() - 1;
	char f;
	string sub;
	while (str[i] == ']') {
		i--;
	}
	int r = i;
	while (str[r] != '[') {
		r--;
	}
	sub = str.substr(r + 1, i - r);
	r--;
	f = str[r];
	i = 2;
	stringstream ss;
	ss << sub;
	int ret;
	ss >> ret;
	if (r == 0) {
		if (m[f] == false || ret >= siz[f]) {
			return 0;
		} else {
			visint[make_pair(f, ret)] = w;
			visbool[make_pair(f, ret)] = 1;
			return 1;
		}
	}
	while (true) {
        if(r <= 0)break;
		if (i == r || r < i)
            if (m[f] == false || ret >= siz[f]) {
                return 0;
            }
		r -= 2;
        ret = visint[make_pair(f, ret)];
		f = str[r];
	}
	if (m[f] == false || ret >= siz[f]) {
		return 0;
	} else {
		visint[make_pair(f, ret)] = w;
		visbool[make_pair(f, ret)] = 1;
		return 1;
	}
}
int main() {
	string str;
	bool stop = false, final = false;
	int ret = 0;
	while (true) {
		m.clear();
		visbool.clear();
		visint.clear();
		siz.clear();
		final = true;
		int bugs = 0, oo = 0;
		while (cin >> str) {
			if (str == ".") {
				if (stop == true) {
					stop = false;
					break;
				} else {
					return 0;
				}
			}
			if (final == true) {
				bugs++;
				stop = true;
				if (str.find('=') == -1) {
					if (ch1(str) == 0)
						final = false;
				} else {
					int mak = str.find('=');
					string st1 = str.substr(mak + 1, SZ(str));
					int kem = kema(st1);
					if (kem == -1) {
						final = false;
					} else {
						bool ff = kema2(kem, str.substr(0, mak));
						if (ff == 0) {
							final = false;
						}
					}
				}
			}
			oo++;
		}
		if (!final)
			cout << bugs << endl;
		else
			cout << 0 << endl;

	}
	return 0;
}
