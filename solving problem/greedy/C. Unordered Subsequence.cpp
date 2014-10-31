#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
#include <memory.h>
#include <climits>
#include <math.h>

using namespace std;
int arr[100000];
int main() {
//	67 499 600 42 23
	int n;
	scanf("%d", &n);
	if (n < 3) {
		cout << 0;
		return 0;
	}
	vector<int> num1, num2;
	bool ch1 = true, ch2 = false;
	int numb = 0;
	cin >> numb;
	int tmp1, tmp2;
	tmp1 = tmp2 = numb;
	for (int i = 2; i <= n; i++) {
		if (num1.size() == 3 || num2.size() == 3)
			break;
		int nn;
		scanf("%d", &nn);
		if (ch1 && nn > tmp1) {
			tmp1 = nn;
		} else if (ch1 && nn < tmp1) {
			tmp1 = nn;
			ch1 = false;
			num1.push_back(i - 1);
		}
		if (!ch1 && nn < tmp1) {
			tmp1 = nn;
		} else if (!ch1 && nn > tmp1) {
			tmp1 = nn;
			ch1 = true;
			num1.push_back(i - 1);
		}
		if (ch2 && nn > tmp2) {
			tmp2 = nn;
		} else if (ch2 && nn < tmp2) {
			tmp2 = nn;
			ch2 = false;
			num2.push_back(i - 1);
		}
		if (!ch2 && nn < tmp2) {
			tmp2 = nn;
		} else if (!ch2 && nn > tmp2) {
			tmp2 = nn;
			ch2 = true;
			num2.push_back(i - 1);
		}
		if (i == n) {
			num1.push_back(i);
			num2.push_back(i);
		}
	}
	if (num1.size() > 2) {
		cout << num1.size() << endl;
		for (int i = 0; i < num1.size(); i++)
			cout << num1[i] << " ";
		return 0;
	} else if (num2.size() > 2) {
		cout << num2.size() << endl;
		for (int i = 0; i < num2.size(); i++)
			cout << num2[i] << " ";
		return 0;

	}
	cout << 0;
	return 0;
}
