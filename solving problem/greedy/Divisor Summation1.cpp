//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2864
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int num;
	cin >> num;
	int count = 1;
	while (num--) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int x = 0, y = 0;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] > arr[i + 1])
				x++;
			else if (arr[i] < arr[i + 1])
				y++;
		}
		cout << "Case " << count << ": " << y << " " << x << endl;
		count++;
	}
	return 0;
}
