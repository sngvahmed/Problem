#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
#define fore(i,a) for(int i = 0;i<a.size();i++)
#define FOR(i,a) for(int i=0;i<a;i++)
using namespace std;
class MovingAvg {
public:
	double difference(int k, vector<double> data) {
		vector<double> num;
		for (int i = 0; i <= data.size() - k; i++) {
			cout << "DATA :: " << data[i] << endl;
			double x = 0;
			for (int q = i; q < (i + k); q++) {
				x += data[q];
			}
			cout << x << endl;
			num.push_back(x / k);
		}
		for (int i = 0; i < num.size(); i++) {
			cout << num[i] << endl;
			int max = 0, min = 0;
			for (int i = 0; i < num.size(); i++) {
				if (num[i] > num[min])
					min = i;
				if (num[i] < num[max])
					max = i;
			}
			return abs(num[max] - num[min]);
		}
	}
};
