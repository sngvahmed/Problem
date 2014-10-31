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
bool Generate(string faka, string floos) {
	stringstream ss;
	int re1, re2;
	ss << faka, ss >> re1, ss.clear(), ss << floos, ss >> re2;
	if (re1 != 0 && re2 == 0) {
		cout << "($0.00)" << endl;
		return 1;
	}
	if (re1 == 0 && re2 == 0) {
		cout << "$0.00" << endl;
		return 1;
	}
	return 0;
}
pair<int, int> changeINT(string faka, string floos) {
	stringstream ss;
	int re1, re2;
	ss << faka, ss >> re1, ss.clear(), ss << floos, ss >> re2;
	return make_pair(re1, re2);
}
string CHNG(string floos) {
	string tm = "";
	reverse(floos.begin(), floos.end());
	for (int i = 0; i < SZ(floos); i += 3) {
		tm += floos.substr(i, 3) + ',';
	}
	floos = tm;
	reverse(floos.begin(), floos.end());
	floos.erase(floos.begin());
	return floos;
}
string CHNGF(string floos) {
	string tm = "";
	for (int i = 0; i < SZ(floos); i += 3) {
		tm += floos.substr(i, 3) + ',';
	}
	floos = tm;
	floos.erase(SZ(floos) - 1);
	if (floos.size() == 1)
		floos += '0';
	return floos;
}
void OUT(pair<int, int> num, string faka, string floos) {
	floos = CHNG(floos);
	if (faka.size() == 1)
		faka += '0';
	if (num.first == 0) {
		cout << '$' << floos << ".00";
	} else {
		if (num.second == 0 && num.first == 0)
			cout << '$' << num.second << ".00";
		else if (num.second == 0)
			cout << '$' << num.second << "." << faka;
		else
			cout << '$' << floos << "." << faka;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	freopen("o.txt", "wt", stdout);
#endif
	string tmp, faka, floos, tmm;
	cin >> tmp;
	bool che = 0;
	if (tmp[0] == '-') {
		tmp.erase(tmp.begin());
		if (tmp.find('.') != -1)
			faka = tmp.substr(tmp.find('.') + 1, SZ(tmp)), floos = tmp.substr(0,
					SZ(tmp) - SZ(faka) - 1);
		else
			faka = "00", floos = tmp;
		if (Generate(faka, floos)) {
			return 0;
		}
		che = 1;
	}
	if (tmp.find('.') != -1)
		faka = tmp.substr(tmp.find('.') + 1, 2), tmm = tmp.substr(
				tmp.find('.') + 1, SZ(tmp)), floos =
				tmp.substr(0, SZ(tmp) - SZ(tmm) - 1);
	else
		faka = "00", floos = tmp;
	pair<int, int> num = changeINT(faka, floos);
	if (num.second == 0) {
		cout << "$0." << faka[SZ(faka) - 1] << faka[SZ(faka) - 2] << endl;
		return 0;
	} else if (che == 1) {
		floos = CHNG(floos);
		if (faka.size() == 1)
			cout << "($" << floos << "." << faka[SZ(faka) - 1] << "0)" << endl;
		else
			cout << "($" << floos << "." << faka[SZ(faka) - 2]
					<< faka[SZ(faka) - 1] << ")" << endl;
		return 0;
	}
	if (che == 1) {
		cout << "(";
		OUT(num, faka, floos);
		cout << ")";
	} else {
		OUT(num, faka, floos);
	}
	cout << endl;
	return 0;
}
