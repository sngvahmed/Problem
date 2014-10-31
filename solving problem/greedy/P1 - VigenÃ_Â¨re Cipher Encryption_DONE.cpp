#include <iostream>
#include <vector>
#include <sstream>
#include <stdio.h>
using namespace std;
char shift(char word, int shifting) {
	int num = word;
	//cout<<num<<endl;
	num = num + shifting;
	if (num > 90)
		num = num - 26;
	word = num;
	//cout<<num<<endl;
	return word;
}
int main() {
	while (true) {
		string x, y;
		cin >> x;
		if (x == "0")
			return 0;
		cin >> y;
		for (int i = 0; i < y.size(); i++) {
				y[i] = shift(y[i], int(x[i%x.size()])-65+1);
		}
		cout << y<<endl;
	}
}
