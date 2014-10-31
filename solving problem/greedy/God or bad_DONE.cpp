#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
using namespace std;
int main() {
	int num;
	scanf("%d", &num);
	bool che = false;
	string q;
	getline(cin, q);
	while (num--) {
		string x;
		getline(cin, x);

		int nu[2] = { 0, 0 };
		for (int i = 0; i < x.size(); i++) {
			if (x[i] == 'b' || x[i] == 'B')
				nu[0]++;
			else if (x[i] == 'g' || x[i] == 'G')
				nu[1]++;
		}
		if (nu[1] > nu[0])
			cout << x << " is GOOD\n";
		else if (nu[1] < nu[0])
			cout << x << " is A BADDY\n";
		else
			cout << x << " is NEUTRAL\n";
	}
	return 0;
}
