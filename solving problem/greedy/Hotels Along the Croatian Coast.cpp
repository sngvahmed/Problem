#include <iostream>
using namespace std;
int main() {
	long long x, d;
	cin >> x >> d;
	long long *num = new long long[x];
	for (long long i = 0; i < x; i++) {
		cin >> num[i];
	}
	long long count = -1;
	for (int i = 0; i < x; i++) {
		long long sum = 0;
		for (int k = i; k < x; k++) {
			sum = sum + num[k];
			if (sum > d)
				break;
			else if (sum > count)
				count = sum;

		}
	}
	cout << count;
	//	cin>>count;
	//	system("pasue");
	return 0;
}
