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
typedef long long int ull;
typedef unsigned long ul;
typedef vector<string> vs;
typedef vector<int> vi;
long long int DP[31000][20], e;
int VL[] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };
bool validate(int tmp) {
	return (tmp >= 0 && tmp <= 9) ? 1 : 0;
}
ull dp(int value, int rem) {
	if (DP[value][rem] != -1)
		return DP[value][rem];
	if (value == 0)
		return 1;
	ull tmp = 0;
	if ((value - VL[rem]) >= 0)
		tmp += dp(value - VL[rem], rem);
	if (validate(rem) && VL[rem] <= value) {
		tmp += dp(value, rem + 1);
	}
	return DP[value][rem] = tmp;
}
ull BuildingTable(int value) {
	for (int i = 0; i < 11 && VL[i] < value; i++) {

	}
}
int main() {
	string num;
	memset(DP, -1, sizeof DP);
	while (cin >> num && num != "0.00") {
		string s1, s2;
		stringstream ss;
		int tmp1, tmp2;
		s1 = num.substr(0, num.find('.')), s2 = num.substr(num.find('.') + 1,
				SZ(num));
		ss << s1, ss >> tmp1, tmp1 *= 100;
		ss.clear();
		ss << s2, ss >> tmp2;
		printf("%3s.%.2s%17lld\n", s1.c_str(), s2.c_str(), dp(tmp1 + tmp2, 0));
//		cout << "  " << num << "              " << dp(tmp1 + tmp2, 0) << endl;
	}
	return 0;
}
