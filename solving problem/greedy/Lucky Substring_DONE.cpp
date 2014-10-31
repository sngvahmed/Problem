//http://codeforces.com/problemset/problem/122/B
#include <cstdlib>
#include <iostream>
#include <vector>
#define fore(i,a) for(int i = 0;i<a.size();i++)
using namespace std;
int main() {
	string num;
	cin >> num;
	int x[2] = { 0 };
	fore(i,num) {
		if (num[i] == '4')
			x[0]++;
		else if (num[i] == '7')
			x[1]++;
	}
	if (x[0] >= x[1] && (x[1] != 0 || x[0] != 0))
		cout << 4;
	else if (x[1] > x[0])
		cout << 7;
	else
		cout << "-1";
	return 0;
}

