#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int num1, num2, num3, num4;
	while (cin >> num1 >> num2 >> num3 >> num4) {
		if (num1 == 0 && num2 == 0 && num3 == 0 && num4 == 0)
			return 0;
		/*
		 1 3 5 9
		 2 2 4 8 (1)
		 0 2 4 6 (2)
		 2 2 2 6 (3)
		 0 0 4 4 (4)
		 0 4 0 4 (5)
		 4 4 4 4 (6) */
		int count = 0;
		while (true) {
			if (num1 == num2 && num3 == num4 && num1 == num4) {
				false;
				cout << count << endl;
				break;
			} else
				count++;
			int n[4];
			n[0] = abs(num1 - num2);
			n[1] = abs(num2 - num3);
			n[2] = abs(num3 - num4);
			n[3] = abs(num4 - num1);
			num1 = n[0];
			num2 = n[1];
			num3 = n[2];
			num4 = n[3];
		}

	}

}
