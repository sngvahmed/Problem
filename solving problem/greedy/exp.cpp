//http://www.codeforces.com/problemset/problem/130/D
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	double a, b, c;
	cin >> a >> b >> c;
	double sum = pow(a, b);
	if (sum > c)
		sum = sum - c;
	cout << int(sum);
	system("pause");
	return 0;
}
