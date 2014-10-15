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
int di[] = { 0, 0, 1, -1, 1, -1, 1, -1 }, dj[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
int n = 0, m = 0, co = 0;
bool vis[22][22][1 << 11];
char arr[22][22];
bool validate(int i, int j) {
	return (i >= 0 && j >= 0 && i < n && j < m) ? 1 : 0;
}
string gereate(string tmp) {
	string num = "";
	FO(i,0,SZ(tmp)-1)
	{
		num += tmp[i];
		if (tmp[i] != tmp[i + 1]) {
			if (tmp[i] < tmp[i + 1])
				while (tmp[i] != tmp[i + 1])
					tmp[i]++, num += tmp[i];
			else if (tmp[i] > tmp[i + 1])
				while (tmp[i] != tmp[i + 1])
					tmp[i]--, num += tmp[i];
			num.erase(SZ(num) - 1);
		}
	}
	num += tmp[SZ(tmp) - 1];
	return num;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
//	freopen("o.txt", "wt", stdout);
#endif
	scanf("%d", &n);
	while (n--) {
		string num;
		cin >> num;
		num = gereate(num);
		int mx = 0;
		FO(i,0,SZ(num))
			mx = max(mx, num[i] - '0');
		while (mx--) {
			FO(i,0,SZ(num))
				if ((num[i] - '0') > mx)
					cout << "+";
				else
					cout << "*";
			cout << endl;
		}
	}
	return 0;
}
// COPY@SNGV
