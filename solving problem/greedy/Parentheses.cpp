#include "bits/stdc++.h"
#include <functional>

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
typedef pair<int, vi> pi;
typedef pair<int, int> vp;
typedef pair<int, pair<int, int> > Hamada;
map<int, vi> var;
int n, m;
bool checkStack(string str) {
	stack<char> stk;
	FO(i , 0 , SZ(str)) {
		if (str[i] == ')') {
			if (stk.size() == 0)
				return 0;
			stk.pop();
		} else
			stk.push('(');
	}
	return 1;
}
void print(int x, int y, string str) {
	if (x < 0 || y < 0)
		return;
	if (x == 0 && y == 0 && checkStack(str)) {
		cout << str << endl;
		return;
	}
	if (x != 0) {
		string tmp = str + '(';
		print(x - 1, y, tmp);
	}
	if (y != 0) {
		string tmp = str + ')';
		print(x, y - 1, tmp);
	}
}
int main() {
	scanf("%d", &n);
	print(n - 1, n, "(");
	return 0;
}
