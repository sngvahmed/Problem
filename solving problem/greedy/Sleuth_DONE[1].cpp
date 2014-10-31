#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stdio.h>
using namespace std;
typedef vector<string> vs;
int main() {
	string Word;
	getline(cin, Word);
	Word.erase(Word.begin() + Word.size() - 1);
	stringstream ss;
	ss << Word;
	string q;
	vector<string> s;
	while (ss >> q) {
		s.push_back(q);
	}

	int e = s.size() - 1;
	char c = s[e][s[e].size() - 1];
	//cout << c;
	if (c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'y' || c == 'u'
			|| c == 'A' || c == 'I' || c == 'E' || c == 'O' || c == 'Y' || c
			== 'U') {
		cout << "YES";
		//	system("pause");
		return 0;
	} else {
		cout << "NO";
		//		system("pause");
		return 0;
	}
	//	system("pause");
	return 0;
}
