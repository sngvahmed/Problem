#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
int main() {
	vector<int> num;
	int howMany;
	cin>>howMany;
	for (int i = 0; i < howMany; i++) {
		num.push_back(0);
		cin >> num[i];
	}
	int counter = 0;
	for (int q = 0; q < num.size(); q++) {
		for (int i = q + 1; i < num.size(); i++) {
			if (num[i] > num[q]) {
				num.push_back(num[i]);
				num.erase(num.begin() + i);
				counter++;
				break;
			}
		}
	}
	cout<<counter;
	system("pause");
	return 0;
}
