#include <sstream>
#include <deque>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>

#define EPS 1.0E-13
#define EQL(x,y) (abs((x)-(y)) < EPS)
#define LT(x,y) (((y)-(x)) >= EPS)
#define GT(x,y) (((x)-(y)) >= EPS)
#define SZ(x) ((int)(x).size())

using namespace std;
class MonotoneSequence {
public:
	//{10, 20, 30, 25, 20, 19, 20, 18, 23}
	int longestMonotoneSequence(vector<int> seq) {
		int q = 0;
		for (int i = 0; i < seq.size(); i++) {
			int counter = i;
			int count = 0;
			for (int q = i + 1; q < seq.size(); q++) {
				if (seq[counter] < seq[q])
					count++;
				else
					break;
				counter++;
			}
			for (int q = i + 1; q < seq.size(); q++) {
				if (seq[counter] < seq[q])
					count++;
				else
					break;
				counter++;
			}
			if (count > q)
				q = count;
		}
		return q;
	}
};
