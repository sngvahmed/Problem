//============================================================================
// Author      : Ahmed nasser
// Version     :
// Copyright   :  Encoder and Decoder
//============================================================================
//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=385
//http://ideone.com/WGakse
#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
#include <memory.h>
#include <climits>

using namespace std;

#define FO(i, a, x) for(int i = a; i < (int)x; i++)
#define FOR(i, x) FO(i, 0, x)
#define RO(i, a, x) for(int i = a; i >= x; i--)
#define ROF(i, x) for(int i = x; i >= 0; i--)
#define FORIT(it, x) for(typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define FOUND(s, x) find(all(s), x) != s.end()
#define NOTFOUND(s, x) find(all(s), x) == s.end()
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MMS(x, v) memset(x, v, sizeof(x))
#define SQ(x) (x) * (x)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<string> vs;
typedef vector<int> vi;
vector<int> x;
map<char, int> number;
int rev(int num) {
	int n = num, r = 1;
	while (num != 0) {
		num = num / 10, r = r * 10;
	}
	r = r / 10, num = n, n = 0;
	while (num != 0) {
		n += num % 10 * r, num = num / 10, r = r / 10;
	}
	return n;
}
vector<string> wo;
void ShowFrom(string word) {
	for (int i = word.size() - 1; i >= 0; i--)
		printf("%d", rev(number[word[i]]));
}
char changeToChar(string f) {
	stringstream ss;
	ss << f;
	int n;
	ss >> n;
	return char(n);
}
void tochar(string num) {
	string g = "";
	for (int i = num.size() - 1; i >= -1; i--) {
		if ((changeToChar(g) >= 'a' && changeToChar(g) <= 'z')
				|| (changeToChar(g) >= 'A' && changeToChar(g) <= 'Z')
				|| changeToChar(g) == ' ' || changeToChar(g) == '!'
				|| changeToChar(g) == ',' || changeToChar(g) == ':'
				|| changeToChar(g) == ';' || changeToChar(g) == '?'
				|| changeToChar(g) == '.') {
			printf("%c", changeToChar(g));
			g = "";
		}
		g += num[i];
	}
}

bool det(string word) {
	FO(i,0,word.size())
		if ((word[i] >= 'a' && word[i] <= 'z')
				|| (word[i] >= 'A' && word[i] <= 'Z') || word[i] == ' '
				|| word[i] == '!' || word[i] == ',' || word[i] == ':'
				|| word[i] == ';' || word[i] == '?' || word[i] == '.')
			return 1;
		else
			return 0;
}

void showchar() {
	char x = 'a';
	FO(i,0,26) {
		number[x] = int(x);
		x = char(int(x) + 1);
	}
	x = 'A';
	FO(i,0,26) {
		number[x] = int(x);
		x = char(int(x) + 1);
	}
	number[' '] = 32, number['!'] = 33, number[','] = 44, number['.'] = 46;
	number[':'] = 58, number[';'] = 59, number['?'] = 63;
}

int main() {
	showchar();
	while (true) {
		string num;
		getline(cin, num);
		bool f = det(num);
		if (f == true) {
			ShowFrom(num);
		} else {
			tochar(num);
		}
		printf("\n");
//		x.clear();
	}

}
