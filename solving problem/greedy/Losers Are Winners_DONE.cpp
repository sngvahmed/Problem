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
	while (true) {
		int N;
		scanf("%d", &N);
		if (N == 0)
			return 0;
		string *word = new string[N * 2];
		string x;
		for (int i = 0; i < N * 2; i++) {
			getline(cin, word[i]);
			if (i == 0) {
				getline(cin, x);
			}
		}
		word[0] = x;
		vector<string> colour;
		vector<double> gain;
		vector<double> lose;
		for (int i = 0; i < N * 2; i++) {
			stringstream ss;
			ss << word[i];
			string name, color;
			double numlose, numgain;
			ss >> name;
			ss >> color;
			ss >> numgain;
			ss >> numlose;
			bool open = false;
			//cout<<word[i]<<endl;
			//cout << name << color << numgain << numlose << endl;
			for (int e = 0; e < colour.size(); e++) {
				if (color == colour[e]) {
					open = true;
					gain[e] += numgain;
					lose[e] += numlose;
				}

			}
			if (open == false) {
				colour.push_back(color);
				gain.push_back(numgain);
				lose.push_back(numlose);
			}

		}
		vector<double> secure;
		for (int i = 0; i < N; i++) {
			double number = (lose[i] * double(100));
			number = number / gain[i];
			secure.push_back(100 - number);
		}
		int s = 0;
		for (int i = 1; i < secure.size(); i++)
			if (secure[s] < secure[i])
				s = i;
			else if (secure[s] == secure[i]) {
				if (colour[s][0] > colour[i][0])
					s = i;
			}
		cout << colour[s] << " " << setprecision(1) << fixed << secure[s]
				<< "%" << endl;
	}
	return 0;
}

