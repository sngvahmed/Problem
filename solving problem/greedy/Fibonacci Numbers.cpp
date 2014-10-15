// fibonanchi BIGint
// http://acm.tju.edu.cn/toj/showp1208.html
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

#define N 4800
using namespace std;
const int BIGINT_SIZE = 1008;
class BigInt {
private:
	char ele[BIGINT_SIZE];
public:
	BigInt() {
		/* initialized with zero */
		ele[0] = '0', ele[1] = '\0';
	}
	BigInt(int t) {
		int len = 0;
		while (t > 0) {
			ele[len] = t % 10 + '0';
			t /= 10;
			len++;
		}
		ele[len] = '\0';
	}
	friend BigInt operator +(const BigInt& tl, const BigInt& tr) {
		/* Assume that tl.len <= tr.len */
		BigInt r;
		int i, carry;
		for (carry = i = 0; tl.ele[i] != '\0'; i++) {
			carry += (tl.ele[i] - '0') + (tr.ele[i] - '0');
			r.ele[i] = carry % 10 + '0';
			carry /= 10;
		}
		while (tr.ele[i] != '\0') {
			carry += (tr.ele[i] - '0');
			r.ele[i] = carry % 10 + '0';
			carry /= 10;
			i++;
		}
		while (carry != 0) {
			r.ele[i] = carry % 10 + '0';
			carry /= 10;
			i++;
		}
		r.ele[i] = '\0';
		return r;
	}
	friend ostream& operator <<(ostream& os, const BigInt& t) {
		for (int i = strlen(t.ele) - 1; i >= 0; i--)
			os << t.ele[i];
		return os;
	}
};
BigInt fib[N];

int main() {
	//  BUILD ::
	fib[1] = fib[2] = BigInt(1);
	for (int i = 3; i < N; i++)
		fib[i] = fib[i - 2] + fib[i - 1];
	int n;
	scanf("%d", &n);
	cout << fib[n] << endl;
	return 0;
}
