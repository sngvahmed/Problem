#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
#define fore(i,a) for(int i = 0;i<a.size();i++)
#define FOR(i,a) for(int i=0;i<a;i++)
using namespace std;

class RollingDiceDivTwo {
public:
	int minimumFaces(vector<string> rolls) {
		fore(i,rolls)
			sort(rolls[i].begin(), rolls[i].end());
		int res = 0;
		fore(i,rolls[0]) {
			int count = 0;
			fore(q,rolls)
				count = max(count, int(rolls[q][i] - '0'));
			res += count;
		}
		return res;
	}
};
