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
	double x, y;
	while (true) {
		cin >> x >> y;
		if (x == -1 || y == -1)
			return 0;
		cout << ceil(max(x, y) / double((min(x, y) + 1))) << endl;
	}
	return 0;
}

