#include "bits/stdc++.h"
#include <functional>
#include <ext/numeric> 
using namespace std;

#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MMS(x, v) memset(x, v, sizeof(x))

string arr[] = { "qwertyuiop", "asdfghjkl;", "zxcvbnm,./" };

pair<int, int> find(char chr) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < SZ(arr[i]); j++) {
			if (chr == arr[i][j]) {
				return mp(i, j);
			}
		}

	}
}

int main() {
	freopen("test.in", "rt", stdin);
	map<char, int> op;
	char s;
	op['R'] = -1, op['L'] = 1;
	string str;
	cin >> s >> str;
	for (int i = 0; i < SZ(str); i++) {
		pair<int, int> indx = find(str[i]);
//		cout << str[i] << " ";
		cout
				<< arr[indx.F][(indx.S + op[s] + SZ(arr[indx.F]))
						% SZ(arr[indx.F])];
	}
	cout << endl;
	return 0;
}
