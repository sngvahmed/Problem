// Mar 14, 2014 ConvexSequence.cpp
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
vector<pair<string, vector<string> > > var;
string str;
class ConvexSequence {
public:
	bool validate(int i, int j) {
		return (i >= 0 && j >= 0 && i < n && j < m) ? 1 : 0;
	}
	long long getMinimum(vector<int> a) {
		if (SZ(a) <= 2)
			return 0;
		long long sum = 0;
		while (true) {
			bool check = true;
			int i = 1;
			while (i < SZ(a)) {
				if (!(a[i - 1] + a[i + 1] >= a[i] * 2)) {
					check = false;
					break;
				}
				i++;
			}
			if (check)
				return sum;
			cout << i << " ";
			sum += (a[i] * 2) - ((a[i - 1] + a[i + 1]) / 2), a[i] = ((a[i - 1]
					+ a[i + 1]) / 2);
			cout << sum << endl;
		}
		return sum;
	}
};
//@CPY::SNGV
