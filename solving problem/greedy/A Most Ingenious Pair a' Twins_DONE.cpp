#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iomanip>
#define fore(i,a) for(int i=0;i<a;i++)
using namespace std;
int main() {
	double x, y;
	while (true) {
		cin >> x >> y;
		if (x == 0 && y == 0)
			return 0;
		double sum = min(x, y) / max(x, y);
		sum = sum * sum;
		sum = 1 - sum;
		sum = sqrt(sum);
		cout << setprecision(3) << fixed << sum << '\n';
	}
	return 0;
}
