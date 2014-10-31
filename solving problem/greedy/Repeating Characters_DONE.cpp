#include <iostream>
#include <vector>
#include <sstream>
/*2
 1 3 ABC
 2 5 /HTP

 Sample Output

 1 AAABBBCCC
 2 /////HHHHHTTTTTPPPPP
 * */
using namespace std;
int main() {
	int p;
	cin >> p;
	for (int i = 0; i < p; i++) {
		int N, R;
		cin >> N >> R;
		string word;
		cin >> word;
		cout << N << " ";
		for (int q = 0; q < word.size(); q++) {
			for (int o = 0; o < R; o++)
				cout << word[q];
		}
		cout << endl;
	}
	//system("pasue");
	return 0;
}
