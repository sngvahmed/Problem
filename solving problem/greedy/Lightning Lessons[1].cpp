#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define fore(i,a) for(int i=0;i<a;i++)
using namespace std;
int main() {
	int x;
	cin >> x;
	while (x--) {
		int r;
		cin >> r;
		int *num = new int[r];
		fore(i,r)
			cin >> num[i];

		int z = 0;
		for (int i = 1; i < r / 2; i++) {
			if (num[z] < num[i])
				z = i;
		}
		z = num[z];
		int q = num[r - 1];
		for (int i = r - 2; i >= r / 2; i--)
			q = abs(q - num[i]);
		if (q == 0 || z == 0)
			cout << "*bunny*" << endl;
		else if (num[0] > num[1])
			cout << "*fizzle*" << endl;
		else {
			for (int i = 0; i < num[1]; i++)
				cout << 'z';
			for (int i = 0; i < num[0]; i++)
				cout << "ap";
			cout << '!';
			cout << endl;

		}
	}
}

