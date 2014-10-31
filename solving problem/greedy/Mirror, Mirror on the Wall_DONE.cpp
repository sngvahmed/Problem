#include <iostream>
using namespace std;
int main() {
	string x;
	while (cin >> x) {
		if (x == "#")
			return 0;
		string s = "";
		//i, o, v, w, and x
		bool open = true;
		for (int i = x.size() - 1; i >= 0; i--) {
			if (x[i] == 'b')
				s += 'd';
			else if (x[i] == 'd')
				s += 'b';
			else if (x[i] == 'p')
				s += 'q';
			else if (x[i] == 'q')
				s += 'p';
			else if (x[i] == 'i' || x[i] == 'o' || x[i] == 'v' || x[i] == 'w'
					|| x[i] == 'x')
				s += x[i];
			else {
				open = false;
				break;
			}
		}
		if (open == false)
			cout << "INVALID" << endl;
		else
			cout << s << endl;

	}

	return 0;
}
