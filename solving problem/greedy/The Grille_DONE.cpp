/*4
 ##O#
 #O#O
 ####
 ###O
 ARAO
 PCEM
 LEEN
 TURC
 # # # #
 # # o #
 # # # o
 o # o #*/
#include <vector>
#include <iostream>
using namespace std;
string *rotate(string *x, int n) {
	string * newword = new string[n];
	int w = n - 1;
	for (int i = 0; i < n; i++) {
		int e = n - 1;
		newword[i] = "";
		for (int q = n - 1; q >= 0; q--) {
			newword[i] += x[q][i];
		}
		w--;
	}
	return newword;
}
int main() {
	int n;
	while (true) {
		cin >> n;
		if (n == 0)
			return 0;
		string *word = new string[n];
		for (int i = 0; i < n; i++)
			cin >> word[i];
		string *code = new string[n];
		for (int i = 0; i < n; i++)
			cin >> code[i];
		string result = "";
		for (int w = 0; w < 4; w++) {
			for (int i = 0; i < n; i++) {
				for (int q = 0; q < n; q++) {
					if (word[i][q] == 'O')
						result += code[i][q];
				}
			}
			word = rotate(word, n);
		}
		cout << result << endl;
	}
	return 0;
}
