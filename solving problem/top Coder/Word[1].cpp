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
using namespace std;
int main() {
	string word;
	cin >> word;
	int wmax = 0, wmin = 0;
	for (int i = 0; i < word.size(); i++) {
		if (int(word[i]) < 97)
			wmax++;
		else
			wmin++;
	}
	if (wmax > wmin) {
		for (int i = 0; i < word.size(); i++) {
			if (word[i] == 'a')
				word[i] = 'A';
			else if (word[i] > 97)
				word[i] = word[i] - 32;
		}
	} else {
		for (int i = 0; i < word.size(); i++) {
			if (word[i] < 97)
				word[i] = word[i] + 32;
		}
	}
	cout << word;
	return 0;
}

