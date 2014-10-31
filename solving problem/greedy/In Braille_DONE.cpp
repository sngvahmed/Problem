#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;
string arr[10] = { ".*\n**\n..", "*.\n..\n..", "*.\n*.\n..", "**\n..\n..",
		"**\n.*\n..", "*.\n.*\n..", "**\n*.\n..", "**\n**\n..", "*.\n**\n..",
		".*\n*.\n.." };
int find(string x) {
	for (int i = 0; i < 10; i++)
		if (x == arr[i])
			return i;
	return -1;
}

int main() {
	while (1) {
		int d;
		char c;
		cin >> d;
		if (d == 0)
			break;
		cin >> c;
		string x, s = "";
		if (c == 'S') {
			cin >> x;
			for (int j = 0; j < 3; j++) {
				for (int i = 0; i < d; i++) {
					// cout<<arr[x[i]-48][1]<<"--------------";
					if (j == 0) {
						s += arr[x[i] - 48][0];
						s += arr[x[i] - 48][1];
						if (i != d - 1)
							s += " ";
					} else if (j == 1) {
						s += arr[x[i] - 48][3];
						s += arr[x[i] - 48][4];
						if (i != d - 1)
							s += " ";
					} else if (j == 2) {
						s += arr[x[i] - 48][6];
						s += arr[x[i] - 48][7];
						if (i != d - 1)
							s += " ";
					}

				}
				s += '\n';
			}
			cout << s;
		} else if (c == 'B') {
			vector<string> arr2;
			for (int k = 0; k < d; k++)
				arr2.push_back("");
			for (int j = 0; j < 4; j++) {
				getline(cin, x);
				for (int i = 0, k = 0; i < x.size(); k++, i += 3) {
					arr2[k] += x[i];
					arr2[k] += x[i + 1];
					if (j != 3)
						arr2[k] += '\n';

				}

			}
			for (int k = 0; k < d; k++)
				cout << find(arr2[k]);
			cout << endl;

		}

	}
	//system("pause");
}
