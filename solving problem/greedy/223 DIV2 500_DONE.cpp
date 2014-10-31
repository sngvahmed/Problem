#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
#define fore(i,a) for(int i = 0;i<a.size();i++)
#define FOR(i,a) for(int i=0;i<a;i++)
using namespace std;
bool ok(const string& s) {
	cout<<s<<endl;
	int R = 0, B = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'R')
			R++;
		else
			B++;
		if (R > B)
			return 0;
	}
	return 1;
}
class BlackAndRed {
public:
	int cut(string deck) {
		int p = deck.size();
		for (int i = 0; i < p; i++) {
			string o = deck.substr(i) + deck.substr(0, i);
			if (ok(o))
				return i;
		}
		return -1;
	}
};
