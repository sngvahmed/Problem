#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <stdio.h>
#include <math.h>
typedef unsigned long long llg;
#define FOR(i,var) for(unsigned long long i=0;i<var;i++)
using namespace std;
int main() {
	string x;
	int num;
	while (true) {
		cin >> num;
		if (num == 0)
			return 0;
		cin >> x;
		int d = x.size() / num;
		string *word = new string[d];
		bool check = true;
		int counter = 0;
		for (int i = 0; i < x.size(); i++) {
			word[counter] = "";
			if (check == true) {
				check = false;
				for (int q = i; q < i + num; q++)
					word[counter] += x[q];
				i = i + num - 1;
			} else {
				check = true;
				for (int q = i + num - 1; q >= i; q--)
					word[counter] += x[q];
				i = i + num - 1;
			}
			counter++;
		}
		string result = "";
		for (int i = 0; i < num; i++) {
			for (int q = 0; q < d; q++) {
				result += word[q][i];
			}
		}
		cout << result << endl;
	}
	system("pause");
	return 0;
}

