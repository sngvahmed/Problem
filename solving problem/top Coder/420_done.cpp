//============================================================================
// Author      : Ahmed nasser
// Copyright   : COPY RITHT To :: ahmed nasser saleh
// Description : 420 DIV2 500
// score :: 150.0
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
#include <string>
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
class YearProgressbar {
public:
	bool isLeap(int n) {
		if (n % 400 == 0)
			return true;

		if (n % 100 == 0)
			return false;

		if (n % 4 == 0)
			return true;

		return false;
	}
	map<string, int> r;
	long long calcTime(int month, int day, int hour, int minutes, bool leap) {
		long long time = 0;
		if (month == 1)
			time = 0;
		else if (month == 2)
			time = 31;
		else if (month == 3)
			time = 59;
		else if (month == 4)
			time = 90;
		else if (month == 5)
			time = 120;
		else if (month == 6)
			time = 151;
		else if (month == 7)
			time = 181;
		else if (month == 8)
			time = 212;
		else if (month == 9)
			time = 243;
		else if (month == 10)
			time = 273;
		else if (month == 11)
			time = 304;
		else if (month == 12)
			time = 334;

		if (leap && month >= 3)
			time++;
		time += day;
		time--;
		time = time * 24 * 60 + hour * 60 + minutes;
		return time;
	}

//	January :: 01, :: 2008 :: 00:00 ::
	vs ta2seem(string data) {
		vs t;
		stringstream ss;
		ss << data;
		while (!ss.eof()) {
			string d;
			ss >> d;
			t.push_back(d);
		}
		t[1] = t[1].substr(0, 2);
		t.push_back(t[3].substr(3, t[3].size()));
		t[3] = t[3].substr(0, 2);
		for (int i = 0; i < t.size(); i++)
			cout << i << " :: " << t[i] << endl;

		return t;
	}
	void Monthret() {
		r["January"] = 1, r["February"] = 2, r["March"] = 3, r["April"] = 4, r["May"] =
				5, r["June"] = 6, r["July"] = 7;
		r["August"] = 8, r["September"] = 9, r["October"] = 10, r["November"] =
				11, r["December"] = 12;
	}
	int TOint(string num) {
		stringstream ss;
		int n = 0;
		ss << num, ss >> n;
		return n;
	}
	double percentage(string currentDate) {
		Monthret();
		vs tt = ta2seem(currentDate);
		double x1 = calcTime(r[tt[0]], TOint(tt[1]), TOint(tt[3]), TOint(tt[4]),
				isLeap(TOint(tt[2])));
		double x2 = calcTime(12, 31, 24, 0, isLeap(TOint(tt[2])));
		cout << x1 << " " << x2 << endl;
		return double(100)*double(x1/x2);

		}
	};
