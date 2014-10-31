//http://www.codeforces.com/problemset/problem/116/A
#include <iostream>
#include <vector>
using namespace std;
int main() {
	int sum;
	cin >> sum;
	int x;
	bool l = true;
	int d = 0;
	do {
		cin >> x;
		if (l == true) {
			l = false;
			sum = sum - x;
		}
		if (l == false) {
			l = true;
			sum = sum + x;
		}
		if (d > sum)
			d = sum;

	} while (x != 0);
	cout<<d;
	return 0;
}
