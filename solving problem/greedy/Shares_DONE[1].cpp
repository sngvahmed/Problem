#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;
int main() {
	pair<int, long long> x;
	while (true) {
		cin >> x.first >> x.second;
		cout << x.second / (x.first + 1);
	}
	return 0;

}
