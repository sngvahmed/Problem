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
#include <math.h>

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
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	freopen("o.txt", "wt", stdout);
#endif
	string num;
	cin >> num;
	stringstream ss;
	num += ',';
	ss << num;
	int tmpn;
	char tmpc;
	vector<int> number;
	map<int, int> vis;
	while (!ss.eof()) {
		ss >> tmpn >> tmpc;
		if (vis[tmpn] == 0)
			vis[tmpn] = 1, number.push_back(tmpn);
	}
	sort(number.begin(), number.end());
	num = "";
	FO(i, 0, SZ(number)) {
		if (i == SZ(number) - 1) {
			cout << number[i] << endl;
			break;
		}
		if (abs(number[i] - number[i + 1]) == 1) {
			int b = i, tm = i;
			++i;
			while (i < SZ(number) && abs(number[b] - number[i]) == 1)
				b++, i++;
			if (i == SZ(number)) {
				cout << number[tm] << "-" << number[b] << endl;
				break;
			} else {
				cout << number[tm] << "-" << number[b] << ",";
				i--;
			}
		} else {
			cout << number[i] << ",";
		}
	}
	return 0;
}
