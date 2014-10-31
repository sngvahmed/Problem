#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stdio.h>
using namespace std;
typedef vector<string> vs;
typedef unsigned long long lln;
int main() {
	string x;
	while (true) {
		getline(cin, x);
		if (x == "*")
			return 0;
		stringstream ss;
		ss << x;
		string z;
		vector<string> d;
		while (ss >> z) {
			d.push_back(z);
		}
		char s = d[0][0];
		int numm = s;
		char q;
		if (numm < 92)
			q = s + 32;
		else
			q = s - 32;
		for (int i = 0; i < d.size(); i++) {
			if (s != d[i][0] && q!=d[i][0]) {
				cout << "N";
			}
		}
		cout << "Y";
	}
	system("pause");
	return 0;
}
