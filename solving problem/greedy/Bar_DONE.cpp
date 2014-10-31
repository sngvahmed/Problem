//http://www.codeforces.com/problemset/problem/56/A
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
using namespace std;
int main() {
	int x;
	scanf("%d", &x);
	string *input = new string[x];
//	vector<string> input;
	for (int i = 0; i < x; i++) {
//		input.push_back("");
        char d[80];
		scanf("%s", d);
		input[i]=d;
	}
	int su = x;
	x = 0;
	for (int i = 0; i < su; i++) {
		if (isdigit(input[i][0]) > 1) {
			stringstream ss;
			ss << input[i];
			int d;
			ss >> d;
			if (d < 18)
				x++;
		} else {
			if (input[i] == "WINE" || input[i] == "CHAMPAGNE" || input[i]
					== "VODKA" || input[i] == "WHISKEY" || input[i]
					== "TEQUILA" || input[i] == "BRANDY" || input[i] == "GIN"
					|| input[i] == "SAKE" || input[i] == "RUM" || input[i]
					== "ABSINTH" || input[i] == "BEER")
				x++;
		}
	}
	printf("%d", x);
	return 0;
}

