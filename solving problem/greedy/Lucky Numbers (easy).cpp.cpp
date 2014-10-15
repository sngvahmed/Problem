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
class pr {
public:
	long long  num, n4, n7;
	pr(int num, int n4, int n7) {
		this->num = num, this->n4 = n4, this->n7 = n7;
	}
};
int main() {
	long long num;
	scanf("%d", &num);
	queue<pr> Q;
	Q.push(pr(0, 0, 0));
	while (!Q.empty()) {
		int sz = Q.size();
		while (sz--) {
			pr tmp = Q.front();
			pr n1 = tmp, n2 = tmp;
			Q.pop();
			tmp.num = tmp.num * 10;
			n1.n4 = tmp.n4 + 1, n2.n7 = tmp.n7 +1;
			n1.num = tmp.num + 4, n2.num = tmp.num + 7;
			if (n1.num >= num && n1.n4 == n1.n7) {
				cout << n1.num ;
				return 0;
			}
			if (n2.num >= num && n2.n7 == n2.n4) {
				cout << n2.num ;
				return 0;
			}
			Q.push(n1);
			Q.push(n2);
		}
	}
	return 0;
}

//99999999
