#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
	int number;
	cin >> number;
	for (int i = 0; i < number; i++) {
		int numnumber;
		cin >> numnumber;
		int *x = new int[numnumber];
		for (int q = 0; q < numnumber; q++) {
			cin >> x[q];
		}
		int sum = 0;
		for (int q = 0; q < numnumber; q++) {
			sum += x[q];
		}
		int average = sum / numnumber;
		int count = 0;
		for (int q = 0; q < numnumber; q++) {
			if (x[q] > average)
				count++;
		}
		double result;
		result = double(count) / double(numnumber);
		result = result * 100;
		cout << setprecision(3) << fixed << result << '\n';
		/*//cout << result << endl;
		 stringstream ss;
		 ss << result;
		 string check = "";
		 ss >> check;
		 stringstream ll;
		 cout << check[6] << endl;
		 ll << check[6];
		 int max;
		 ll >> max;
		 if (max >= 5)
		 check[5] = check[5] + '1' - '0';
		 check.erase(check.begin()+6);
		 cout << check;*/
	}
	return 0;
}
