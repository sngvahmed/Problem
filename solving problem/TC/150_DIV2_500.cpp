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
int di[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dj[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
string ret = "ABCDEF ";
bool vis[189][189];
int lvl = -1;
class InterestingDigits {
public:
	string toBase(long long num, int base) {
		if (num == 0)
			return "0";
		string str;
		while (num != 0) {
			int nlet = num % base;
			num /= base;
			if (nlet < 0) //for negative base
				num++, nlet += (-1 * base);
			if (nlet < 10)
				str += (nlet + '0');
			else
				str += (nlet - 10 + 'A');

		}
		reverse(str.begin(), str.end());
		return str;
	}
	long long toDecimal(string s, int base) {
		long long v, i, result = 0;
		for (i = 0; i < (int) s.size(); i++) {
			if (s[i] >= '0' && s[i] <= '9')
				v = s[i] - '0';
			else
				v = s[i] - 'A' + 10;
			result = result * base + v;
		}
		return result;
	}
	int sumOfIT(int y, int x, char tmp) {
		return (x + y) % tmp;
	}
	vector<int> digits(int base) {
		vector<int> num;
		for (int i = base - 1; i > 1; i--) {
			bool ch = true;
			FO(r,1,base) {
				int tm = i * r;
				string toB = toBase(tm, base);
				char sum = toBase(i, base)[0];
				int ret = 0;
				FO(i,0,SZ(toB)) {
					ret = sumOfIT(ret,
							(toB[i] >= 'A' && toB[i] <= 'Z') ?
									toB[i] - 'A' + 10 : toB[i] - '0',
							(sum >= 'A' && sum <= 'Z') ?
									sum - 'A' + 10 : sum - '0'), ret %= '0';
					cout << ret << toB[i] << sum << endl;
				}
				cout << endl;
				ret %= sum;
				cout << i << " " << ret << " " << toB << " " << sum << " "
						<< int(sum) << endl;
				if (ret != 0) {
					ch = false;
					break;
				}
			}
			if (ch)
				num.push_back(i);
		}
		reverse(num.begin(), num.end());
		return num;
	}
};
