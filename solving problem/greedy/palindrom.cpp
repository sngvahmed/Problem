#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;
bool palindrome_mirr(string word, string pa) {
	int count = pa.size() - 1;
	for (int i = 0; i <= pa.size() / 2; i++, count--)
		if (pa[i] != word[count])
			return false;
	return true;
}
bool palindrome(string word) {
	int count = word.size() - 1;
	for (int i = 0; i <= word.size() / 2; i++, count--)
		if (word[i] != word[count])
			return false;
	return true;
}

string REVERSE(string word) {
	for (int i = 0; i < word.size(); i++) {
		//	cout << word[i] << "    ";
		if (word[i] == 'E')
			word[i] = '3';
		else if (word[i] == 'J')
			word[i] = 'L';
		else if (word[i] == 'L')
			word[i] = 'J';
		else if (word[i] == 'S')
			word[i] = '2';
		else if (word[i] == 'Z')
			word[i] = '5';
		else if (word[i] == '1')
			word[i] = '1';
		else if (word[i] == '2')
			word[i] = 'S';
		else if (word[i] == '3')
			word[i] = 'E';
		else if (word[i] == '5')
			word[i] = 'Z';
		//	cout << word[i] << endl;
	}
	return word;
}

int main() {
	string word;
	char words[100];
	while (scanf("%s", words) != -1) {
		word = words;
		string reverse = REVERSE(word);
		//	cout<<"/n";
		if (palindrome(word)) {
			//cout << reverse << "    " << word << endl;
			if (palindrome_mirr(reverse, word))
				cout << word << " -- is a mirrored palindrome.\n";
			else
				cout << word << " -- is a regular palindrome.\n";
		} else if (palindrome_mirr(reverse, word))
			cout << word << " -- is a mirrored string.\n";
		else
			cout << word << " -- is not a palindrome.\n";
	}
	return 0;
}
