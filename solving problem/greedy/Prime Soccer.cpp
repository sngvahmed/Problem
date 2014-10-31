#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
int HowManyGoal(int x) {
	int count = 0;
	if (x == 2)
		return 1;
	for (int i = 2; i < x; i++) {
		bool check = false;
		for (int q = 2; q < x; q++)
			if (i % q != 0) {
				check = true;
				break;
			}
		if (check == false)
			count++;
	}
	return count;
}
int main() {
	int score1, score2;
	cin >> score1 >> score2;
	int x1 = HowManyGoal(score1);
	int x2 = HowManyGoal(score2);
	cout << (double(x1) / double(score1)) * 100;
	cout << (double(x2) / double(score2)) * 100;
	system("pause");
	return 0;
}
