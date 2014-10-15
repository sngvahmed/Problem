//============================================================================
// Author      : Ahmed nasser
// Version     :
// Copyright   :  Life Without Zeros
//============================================================================
//http://codeforces.com/problemset/problem/75/A
//http://ideone.com/WGakse
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
string removezero(string num) {
	string s = "";
	FO(i,0,num.size()) {
		if (num[i] != '0')
			s += num[i];
	}
	return s;
}

int TOint(string num) {
	stringstream ss;
	int n = 0;
	ss << num, ss >> n;
	return n;
}
string TOstring(int num) {
	stringstream ss;
	string n="";
	ss << num, ss >> n;
	return n;
}
int main() {
	string n1, n2;
	cin >> n1 >> n2;
	if (TOint(removezero(TOstring(TOint(n1) + TOint(n2))))
			== (TOint(removezero(n1)) + TOint(removezero(n2)))) {
		cout << "YES";
	} else
		cout << "NO";
}
