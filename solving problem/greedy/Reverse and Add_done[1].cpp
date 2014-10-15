//============================================================================
// Author      : Ahmed nasser
// Version     :
// Copyright   : 10018 - Reverse and Add
// Description : Hello World in C++, Ansi-style
//============================================================================
//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=959
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
#define FO(i, a, x,e) for(int i = a; i < (int)x; i++,e--)
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
bool palind(string word) {
	int e = word.size() - 1;
	FO(i,0,word.size(),e) {
		if (word[e] != word[i])
			return 0;
	}
	return 1;
}
string sum(string num) {
	unsigned int x, y;
	stringstream ss;
	ss << num, ss >> x, ss.clear();
	string g = "";
	for (int i = num.size() - 1; i >= 0; i--)
		g += num[i];
	ss << g, ss >> y, num = "";
	x += y;
	ss.clear(), ss << x, ss >> num;
	return num;
}
int main() {
	int ss;
	scanf("%d", &ss);
	while (ss--) {
		string word;
		cin >> word;
		int n = 0;
		while (!palind(word)) {
			n++;
			word = sum(word);
		}
		cout << n << " " << word << endl;
	}
	return 0;
}
