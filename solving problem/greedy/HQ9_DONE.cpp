//http://www.codeforces.com/problemset/problem/133/A
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <math.h>
typedef unsigned long long llg;
#define FOR(i,var) for(unsigned long long i=0;i<var;i++)
using namespace std;
int main() {
	string x;
	cin >> x;
	for (int i = 0; i < x.size(); i++)
		if (x[i] == 'H') {
			cout << "YES";
			return 0;
		} else if (x[i] == '+') {
			cout << "YES";
			return 0;
		} else if (x[i] == '9') {
			cout << "YES";
			return 0;
		} else if (x[i] == 'Q') {
			cout << "YES";
			return 0;
		}
	cout << "NO";
	return 0;
}
