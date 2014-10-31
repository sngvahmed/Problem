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
class CondorcetVoting {
public:
	int winner(vector<string> votes) {
		for (int i = 0; i < votes[0].size(); i++) {
			int win = 0;
			for (int y = 0; y < votes[0].size(); y++) {
				if (i == y)
					continue;
				int right = 0;
				int left = 0;
				for (int q = 0; q < votes.size(); q++) {
					if (votes[q][i] > votes[q][y])
						right++;
					else if (votes[q][i] < votes[q][y])
						left++;
				}
				if (right >= left)
					break;
				else if (right < left)
					win++;
			}
			if (win == votes[0].size() - 1)
				return i;
		}
		return -1;
	}
};
