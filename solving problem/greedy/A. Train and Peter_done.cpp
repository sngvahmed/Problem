//============================================================================
// Author      : Ahmed nasser
// Version     :
// Copyright   : A. Train and Peter
// Description : Hello World in C++, Ansi-style
//============================================================================
//http://codeforces.com/problemset/problem/8/A//http://ideone.com/WGakse
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
bool FindITfor(string word, string ser1, string ser2) {
	for (int i = 0; i < word.size(); i++) {
		bool s = true;
		int n;
		for (n = 0; n < ser1.size(); n++) {
			if (word[i + n] != ser1[n]) {
				s = false;
				break;
			}
		}
		if (s == true && ser2 != "-!!-") {
			return FindITfor(word.substr(i + n, word.size()), ser2, "-!!-");

		} else if (s == true && ser2 == "-!!-")
			return 1;
	}
	return 0;
}
bool FindITbak(string word, string ser1, string ser2) {
	string g = "";
	for (int i = word.size() - 1; i >= 0; i--)
		g += word[i];
	//cout << g << endl;
	return FindITfor(g, ser1, ser2);
}
int main() {
	string word, full1, full2;
	cin >> word >> full1 >> full2;
	bool forward = 0, back = 0;
	forward = FindITfor(word, full1, full2);
	back = FindITbak(word, full1, full2);
	//cout << forward << back << " " << endl;
	if (forward == 1 && back == 1)
		cout << "both";
	else if (forward == 1)
		cout << "forward";
	else if (back == 1)
		cout << "backward";
	else
		cout << "fantasy";
	return 0;
}
