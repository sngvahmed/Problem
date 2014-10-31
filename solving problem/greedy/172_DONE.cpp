#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
#define For(i,a) for(int i=0;i<a.size();i++)
class SkipRope {
public:
	vector<int> partners(vector<int> candidates, int height) {
		sort(candidates.begin(), candidates.end());
		//		int *sum = new int[candidates.size()];
		//		For(i,candidates){
		//			sum[i]=candidates[i]-height;
		//		}
		int s = candidates.size() - 1;
		for (int i = candidates.size() - 1; i >= 0; i--) {
			if (abs(candidates[s] - height) > abs(candidates[i] - height))
				s = i;
		}
		vector<int> result;
		result.push_back(candidates[s]);
		candidates.erase(candidates.begin() + s);
		s = candidates.size() - 1;
		for (int i = candidates.size() - 1; i >= 0; i--) {
			if (abs(candidates[s] - height) > abs(candidates[i] - height))
				s = i;
		}
		result.push_back(candidates[s]);
		return result;
	}
};
