#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
int main() {
	string word, fin;
	char WholeWord;
	int searchIndx;
	getline(cin, word);
	cin >> fin >> WholeWord >> searchIndx;
	if (WholeWord == 'N') {
		string result = "";
		for (int i = searchIndx; i < word.size(); i++)
			result += word[i];
		if (result.find(fin) == -1)
			cout << -1;
		else
			cout << result.find(fin) + searchIndx;
	} else {
		string result = "";
		for (int i = searchIndx; i < word.size(); i++)
			result += word[i];
		stringstream ss;
		ss << result;
		vector<string> finden;
		string q;
		while (ss >> q)
			finden.push_back(q);
		bool check = true;
		for (int n = 0; n < finden.size(); n++)
			if (finden[n] == fin)
				check = false;
		if (check == false)
			cout << result.find(fin) + searchIndx;
		else
			cout << -1;
	}
	system("pause");
	return 0;
}
