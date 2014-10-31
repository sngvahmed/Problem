#include <iostream>
using namespace std;
int main() {
	int s;
	//int sum;
	cin >> s;
	int x[1000], y[1000];
	int count = 0;
	x[i] = 1;
	y[0] = 1;
	for (int i = 1; i <= s; i++) {
		if (x[i] * i < i) {
			count++;
		}
	}
	return 0;
}
