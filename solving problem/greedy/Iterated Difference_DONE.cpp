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
	int cou = 0;
	while (true) {
		cou++;
		cin >> x;
		vector<int> num;
		if (x == 0)
			return 0;
		for (int i = 0; i < x; i++) {
			num.push_back(0);
			cin >> num[i];
		}
		int counter = -1;
		while (true) {
			counter++;
			int y = num[0];
			for (int i = 0; i < num.size() - 1; i++)
				num[i] = abs(num[i + 1] - num[i]);
			num[num.size() - 1] = abs(num[num.size() - 1] - y);
			bool ch = true;
			for (int q = 0; q < num.size(); q++)
				if (num[q] != 0) {
					ch = false;
					break;
				}
			if (ch == true)
				break;
			if (counter > 1000)
				break;
		}
		if (counter > 1000)
			cout << "Case " << cou << ": not attained" << endl;
		else
			cout << "Case " << cou << ": " << counter << " iterations" << endl;
	}

}

