// Mar 9, 2014 TriFibonacci.cpp
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
class TriFibonacci {
public:
	int complete(vector<int> A) {
		int ret = 0;
		FO(i,0,SZ(A)) {
			if (A[i] == -1) {
				if (i >= 3) {
					A[i] = A[i - 1] + A[i - 2] + A[i - 3];
					ret = A[i];
				} else {
					if (i == 0) {
						A[i] = A[i + 3] - (A[i + 1] + A[i + 2]);
					} else if (i == 1) {
						A[i] = A[i + 2] - (A[i + 1] + A[i - 1]);
					} else {
						A[i] = A[i + 1] - (A[i - 2] + A[i - 1]);
					}
					ret = A[i];
				}
			} else if (i >= 3 && A[i] != A[i - 1] + A[i - 2] + A[i - 3]) {
				return -1;
			}
		}
		return ret;
	}
};
//@CPY::SNGV
