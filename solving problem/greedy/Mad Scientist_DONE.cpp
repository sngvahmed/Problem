#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int x;
	while (cin >> x) {
		if (x == 0)
			return 0;
		int arr[x + 1];
		arr[0] = 0;
		for (int i = 1; i <= x; i++)
			cin >> arr[i];
		vector<int> n;
		for (int i = 0; i < x; i++) {
			for (int q = 0; q < abs(arr[i + 1] - arr[i]); q++)
				n.push_back(i + 1);
		}
		for (int i = 0; i < n.size(); i++)
			if (i == n.size() - 1)
				cout << n[i];
			else
				cout << n[i] << " ";
		cout << endl;
	}

	return 0;
}
