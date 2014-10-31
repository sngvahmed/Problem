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

using namespace std;
int main() {
	unsigned long long n;
	cin >> n;
	while (n > 1) {
		if (n % 2 == 0)
			n = n / 2;
		else
			n = (3 * n) + 3;
		if (n == 1) {
			cout << "TAK";
			return 0;
		}
		if (n % 3 == 0) {
			cout << "NIE";
			return 0;
		}
	}
	return 0;
}
