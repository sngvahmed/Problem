#include <iostream>
using namespace std;
class DigitsSum {
public:
	int sizee(int n) {
		int count = 0;
		while (n != 0) {
			n = n / 10;
			count++;
		}
		return count;
	}
	int lastDigit(int n) {
		int sum = 0;
		while (sizee(n) != 1) {
			sum = 0;
			int q = sizee(n);
			for (int i = 0; i < q; i++) {
				cout << n % 10 << endl;
				sum = sum + (n % 10);
				n = n / 10;
			}
			n = sum;
		}
		return n;
	}

};
