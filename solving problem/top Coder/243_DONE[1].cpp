#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class ComputationalComplexity {
public:
	//constant[i]*Npower[i]*lnlogPower[i](N)
	int powerr(int x, int po) {
		int sum = 1;
		for (int i = 0; i < po; i++)
			sum *= x;
		//cout<<sum<<endl;
		return sum;
	}
	/*
	 Standard Output:
	 5    160000    -inf
	 50    400    0
	 45    400    0
	 0
	 0*/
	int fastestAlgo(vector<int> constant, vector<int> power,
			vector<int> logPower, int N) {
		vector<int> back;
		for (int i = 0; i < constant.size(); i++) {
			back .push_back(constant[i] * powerr(N, power[i]) * powerr(log(N),
					logPower[i]));
		}
		int q = 0;
		for (int i = 1; i < back.size(); i++)
			if (back[q] > back[i])
				q = i;

		return q;
	}
};
