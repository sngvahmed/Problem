//http://codeforces.com/problemset/problem/160/B
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fore(i,a) for(int i=0;i<a.size();i++)
#define FOR(q,e) for(int q=0;q<e;q++)
int main() {
	int x;
	cin >> x;
	string word;
	cin >> word;
	int c = word.size() - 1;
	string tries = word;
	for (int i = 0; i < tries.size() / 2; i++, c--) {
		bool s = true;
		int w = 0;
		for (int q = 0; q < tries.size() / 2; q++) {
			if (tries[q] <= tries[w] && tries[q] > tries[c]) {
				s = false;
				w = q;
			}
		}
		if (s == false) {
			//cout << tries[c];
			tries.erase(tries.begin() + c);
			//cout << "   " << tries[w] << endl;
			tries.erase(tries.begin() + w);
			//cout << tries << endl;
			c = tries.size();
			i = -1;
		}
	}
	if (tries.size() == 0) {
		cout << "YES";
		return 0;
	}
	c = word.size() - 1;
	tries = word;
	for (int i = 0; i < tries.size() / 2; i++, c--) {
		bool s = true;
		int w = 0;
		for (int q = 0; q < tries.size() / 2; q++) {
			if (tries[q] >= tries[w] && tries[q] < tries[c]) {
				s = false;
				w = q;
			}
		}
		if (s == false) {
			//cout << tries[c];
			tries.erase(tries.begin() + c);
			//cout << "   " << tries[w] << endl;
			tries.erase(tries.begin() + w);
			//cout << tries << endl;
			c = tries.size();
			i = -1;
		}
	}
	if (tries.size() == 0) {
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO";
	return 0;
}
