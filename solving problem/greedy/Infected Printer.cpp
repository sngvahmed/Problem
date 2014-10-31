#include <iostream>
using namespace std;
int main() {
	string word;
	cin >> word;
	string result = "";
	for (int i = word.size() / 2; i < word, size(); i++)
		result += word[i];
	for (int i = 0; i < word.size() / 2; i++)
		result += word[i];
	cout << result;
	return 0;
}
