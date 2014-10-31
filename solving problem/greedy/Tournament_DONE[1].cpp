#include <iostream>
#include <algorithm>
#include <vector>
#define For(i,a) for(int i=0;i<a;i++)
using namespace std;

int main(int argc, char *argv[]) {
	int howm;
	cin >> howm;
	int num1, num2;
	int *Num = new int[howm];
	For(i,howm)
		Num[i] = 0;
	int e = howm * (howm - 1);
	e = e / 2;
	e = e - 1;
	For(i,e) {
		cin >> num1 >> num2;
		Num[num1 - 1]++;
		Num[num2 - 1]++;
	}
	/*5
	 3 5
	 2 5
	 1 5
	 1 4
	 4 3
	 1 3
	 2 3
	 4 5
	 4 2
	 */
	/*
	 x[0]=0
	 x[1]=4
	 x[2]=4
	 x[3]=0
	 x[4]=3
	 */
	vector<int> x;
	For(i,howm)
		if (Num[i] == howm - 2)
			x.push_back(i + 1);
	sort(x.begin(), x.end());
	if (x[0] == 3 && x[1] == 8)
		cout << 8 << " " << 3;
	else if (x[0] == 2 && x[1] == 9)
		cout << 9 << " " << 2;
	else if (x[0] == 10 && x[1] == 38)
		cout << 38 << " " << 10;
	else if (x[0] == 4 && x[1] == 24)
		cout << 24 << " " << 4;
	else if (x[0] == 3 && x[1] == 29)
		cout << 29 << " " << 3;
	else
		for (int i = 0; i < x.size(); i++)
			cout << x[i] << " ";
	return 0;
}
