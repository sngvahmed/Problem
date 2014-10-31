#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include<stdio.h>
#include<string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define Fors(i,a) for(int i=0;i<a.size();i++)
#define Fors(k,a) for(int i=0;i<a.size();i++)
typedef long long ll;
typedef unsigned long long ull;
class Highscore {
public:
	int getRank(vector<int> scores, int newscore, int places) {
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < scores.size(); i++) {
			if (newscore > scores[i])
				sum1++;
			else
				sum2++;
		}
		if (sum2 >= places)
			return -1;
		return sum1 + 1;

	}

};

