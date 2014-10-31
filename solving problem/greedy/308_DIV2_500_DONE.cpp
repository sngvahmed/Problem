#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fore(i,a) for(int i=0;i<a.size();i++)
#define FOR(q,e) for(int q=0;q<e;q++)
class HuffmanDecoding {
public:
	int check(string word, vector<string> dictionary) {
		for (int i = 0; i < dictionary.size(); i++)
			if (word == dictionary[i])
				return i;
		return -1;
	}

	string decode(string archive, vector<string> dictionary) {
		string result = "";
		string s = "";
		fore(i,archive) {
			s += archive[i];
			cout << s << endl;
			if (check(s, dictionary) != -1) {
				char x = 65 + check(s, dictionary);
				cout << x << endl;
				result += 65 + check(s, dictionary);
				s = "";
			}
		}
		return result;
	}
};
