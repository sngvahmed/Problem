//95%
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define Fors(i,a) for(int i=0;i<a.size();i++)
typedef long long ll;
typedef unsigned long long ull;
class EyeDrops {
public:
	double closest(int sleepTime, int k) {
		if (k == 1)
			return double(24 * 60);
		double min = double(double(24) / double(k)); //24/2 = 12
		double wakeup = 24 - sleepTime; // 16
		double sum = wakeup / (double(k) - 1);
		if(sum > min)
			return min * 60 ;
		else
			return sum * 60 ;
	}

};

