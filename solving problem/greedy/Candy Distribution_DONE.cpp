#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#define FOR(i,var) for(unsigned long long i=0;i<var;i++)
using namespace std;

int main() {
	unsigned long long x;
	while (scanf("%lld", &x) == 1) {

		if (x == 0)
			return 0;
		vector<unsigned long long> z(x);
		vector<unsigned long long> y(x);
		//int i;
		FOR(i,x) {
			scanf("%lld", &z[i]);
		}
		FOR(i,x) {
			scanf("%lld", &y[i]);
		}
		sort(z.rbegin(), z.rend());
		sort(y.begin(), y.end());
		unsigned long long sum = 0;
		FOR(i,z.size()) {
			sum += (z[i] * y[i]);
		}
		printf("%lld\n", sum);
	}
}
