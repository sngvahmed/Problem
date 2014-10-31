#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main() {
	string word;
	while (cin >> word) {
		if (word == "#")
			return 0;
		int x[3] = { 0, 0, 0 };
		for (int i = 0; i < word.size(); i++) {
			if (word[i] == 'Y')
				x[0]++;
			else if (word[i] == 'N')
				x[1]++;
			else if (word[i] == 'A')
				x[2]++;
		}
		if (x[2] >= ceil((float)word.size()/2))
			cout << "need quorum";
		else if (x[1] > x[0])
			cout << "no";
		else if (x[0] > x[1])
			cout << "yes";
		else
			cout << "tie";
			cout<<endl;
	}

	return 0;
}
