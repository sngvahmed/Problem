#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;
class KDoubleSubstrings {
public:
	int howMuch(vector<string> str, int k) {
		string result = "";
		for (int i = 0; i < str.size(); i++)
			result += str[i];
		vector<string> x;
		for (int i = 0; i < result.size(); i++) {
			for (int s = 2; s <= result.size(); s += 2) {
				x.push_back(result.substr(0, s));
			}
			result.erase(result.begin() + i);
			i--;
		}
		int coun = 0;
		int countr = 0;
		int co = 0;
		for (int i = 0; i < x.size(); i++) {
			int n = 0;
			coun = 0;
			countr = 0;
			for (int s = x[i].size() / 2; s < x[i].size(); s++) {
				if (x[i][n] != x[i][s])
					countr++;

				if (countr == 1) {
					coun++;
					countr = 0;
				}
				n++;
			}
			if (coun <= k)
				co++;
		}
		return co;
	}
};
