//95
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
#define For(i,a) for(int i=0;i<a.size();i++)
class ClockWalk {
public:
	int finalPosition(string flips) {
		int x = 12;
		For(i,flips) {
			if (flips[i] == 'h')
				x = x + i + 1;
			else
				x = x - (i + 1);
			if (x > 24)
				x -= 24;
			if (x < 0)
				x += 24;
			cout << x << endl;
		}
		if (x > 12) {
			return x - 12;
		} else
			return x;
	}

};
