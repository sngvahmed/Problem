//145
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include<stdio.h>
#include<string.h>
#include <math.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define Fors(i,a) for(int i=0;i<a.size();i++)
typedef long long ll;
typedef unsigned long long ull;
class PassingGrade {
public:
	int pointsNeeded(vector<int> pointsEarned, vector<int> pointsPossible,
			int finalExam) {
		double ttrue = 0, tposipple = 0;
		Fors(i,pointsEarned)
			ttrue += pointsEarned[i];
		Fors(i,pointsPossible)
			tposipple += pointsPossible[i];
		tposipple += finalExam;
		double result = ceil((double) tposipple * 65 / 100.0);
		if (result < finalExam)
			return -1;
		else
			return result - ttrue;
	}

};

