#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class PalindromeDecoding {
public:
	string decode(string code, vector<int> position, vector<int> length) {
		for (int i = 0; i < position.size(); i++) {
			string s = "";
			for (int n = position[i]; n < position[i] + length[i]; n++) {
				s += code[n];
			}
			cout << s << endl;
			string result = "";
			for (int q = 0; q < code.size(); q++) {
				result += code[q];
				if (q == (position[i] + length[i] - 1)) {
					for (int e = s.size() - 1; e >= 0; e--) {
						cout << s[e];
						result += s[e];
					}
				}
			}
			cout << "ahmed :: " << result << endl;
			code = result;
		}
		return code;
	}
};
