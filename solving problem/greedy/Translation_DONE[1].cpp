#include <iostream>
using namespace std;
int main() {
	string x[2];
	cin >> x[0] >> x[1];
	int q = x[1].size() - 1;
	for (int i = 0; i < x[0].size(); i++) {
		if (x[1][q] != x[0][i]) {
			cout << "NO";
//			system("pause");
			return 0;
		}
		q--;
	}
	cout << "YES";
//	system("pause");
	return 0;
}
