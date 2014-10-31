#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;
int main() {
	int n;
	//  TTT  , TTH , THT  ,THH  ,HTT  , HTH  , HHT   HHH
	//  x[0] ,x[1] , x[2] ,x[3] , x[4], x[5] , x[6] ,x[7]
	scanf("%d", &n);
	while (n--) {
		string word;
		int d;
		scanf("%d", &d);
		cin >> word;
		int num[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		for (int i = 0; i < word.size(); i++) {
			string result = "";
			for (int q = i; q < i + 3; q++)
				result += word[q];
			if (result == "TTT")
				num[0]++;
			else if (result == "TTH")
				num[1]++;
			else if (result == "THT")
				num[2]++;
			else if (result == "THH")
				num[3]++;
			else if (result == "HTT")
				num[4]++;
			else if (result == "HTH")
				num[5]++;
			else if (result == "HHT")
				num[6]++;
			else if (result == "HHH")
				num[7]++;
		}
		cout << d << " ";
		cout << num[0] << " " << num[1] << " " << num[2] << " " << num[3]
				<< " " << num[4] << " " << num[5] << " " << num[6] << " "
				<< num[7];
		cout << endl;
	}
	return 0;
}
