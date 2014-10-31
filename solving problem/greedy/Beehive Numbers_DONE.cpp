#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stdio.h>
using namespace std;
typedef vector<string> vs;
typedef unsigned long long lln;

int main() {

	long long num;
	while (true) {
		cin >> num;
		if (num == -1)
			return 0;
		long long counter = 1;
		int n = 1;
		while (counter <= num) {
			if (counter == num || num == 1) {
				cout << "Y" << endl;
				break;
			}
			counter += (n * 6);
			n++;
		}
		if (counter > num)
			cout << "N" << endl;
	}
	return 0;
}
