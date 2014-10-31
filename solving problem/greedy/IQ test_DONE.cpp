//http://www.codeforces.com/problemset/problem/25/A
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
	int x;
	cin >> x;
	int *num = new int[x];
	for (int i = 0; i < x; i++)
		cin >> num[i];
	int even = 0;
	int odd = 0;
	for (int i = 0; i < x; i++) {
		if (num[i] % 2 == 0)
			even++;
		else
			odd++;
	}
	if (even > odd) {
		int r;
		for (int i = 0; i < x; i++) {
			if (num[i] % 2 != 0)
				r = i + 1;
		}
		cout << r;
		return 0;
	} else {
		int r;
		for (int i = 0; i < x; i++) {
			if (num[i] % 2 == 0)
				r = i + 1;
		}
		cout << r;
		return 0;
	}
	return 0;
}

