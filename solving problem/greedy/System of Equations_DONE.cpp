#include <iostream>
using namespace std;
int main() {
	int x, y;
	cin >> x >> y;
	int count = 0;
	//9   3
	for (int i = 0; i <= x; i++) {
		for (int q = 0; q <= y; q++) {
			if (((i * i) + q) == x && ((i + (q * q)) == y))
				count++;
		}
	}
	cout << count;
	system("pause");
	return 0;
}
