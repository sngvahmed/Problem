#include <iostream>
#include <vector>
#include <set>
#include <sstream>
using namespace std;
bool isplm(string x) {
	int q = x.size() - 1;
	for (int i = 0; i < x.size() / 2; i++) {
		if (x[i] != x[q])
			return 0;
		q--;
	}
	return 1;
}
int main() {
	string x;
	cin >> x;
	int q = -1;
	for (int i = x.size() - 1; i >= 0; i--) {
		stringstream ss;
		ss << x[i];
		int w;
		ss >> w;
		for (int o = w + 1; o < 9; o++)
		char l = o;
		//x[i] = o;
		if (isplm(x)) {
			cout << x;
			break;
		}
	}
	return 0;
}
