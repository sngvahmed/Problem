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
#define SF(x) scanf("%d" , %x)
int sz, cur;
string str;
int differ(char x, char y) {
	if (x > y) {
		int x1 = x - y;
		int comp = (25 - x1) + 1;
		return min(comp, x1);
	} else {
		int x1 = y - x;
		int comp = (25 - x1) + 1;
		return min(comp, x1);
	}
}
pair<int, int> nearstChar(int indx) {
	int ret1 = -1, ret2 = -1;
	for (int i = indx; i < SZ(str) / 2; i++)
		if (str[i] != str[(SZ(str) - i) - 1]) ret1 = i;

	for (int i = indx; i >= 0; i--)
		if (str[i] != str[(SZ(str) - i) - 1]) ret2 = i;

	return mp(ret1, ret2);
}

int run() {
	pair<int, int> indx = nearstChar(cur);
	int tot = -1;
	if (indx.F == -1 && indx.S == -1) {
		return 0;
	} else if (indx.S == -1) {
		while (cur <= indx.F)
			tot++, tot += differ(str[cur], str[(sz - cur) - 1]), cur++;
		return tot;
	} else if (indx.F == -1) {
		while (cur >= indx.S)
			tot++, tot += differ(str[cur], str[(sz - cur) - 1]), cur--;
		return tot;
	} else {
		if ((indx.F - cur) < (cur - indx.S)) {
			tot += (indx.F - cur), cur = indx.F;
			while (cur >= indx.S) {
				tot++;
				tot += differ(str[cur], str[(sz - cur) - 1]);
				str[cur] = str[(sz - cur) - 1];
				cur--;
			}
		} else {
			tot += (cur - indx.S), cur = indx.S;
			while (cur <= indx.F)
				tot++, tot += differ(str[cur], str[(sz - cur) - 1]), cur++;
		}
		return tot;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	cin >> sz >> cur >> str;
	if (cur > sz / 2) cur = sz - cur;
	else cur--;
	cout << run() << endl;
	return 0;
}
