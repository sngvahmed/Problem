//============================================================================
// Author      : Ahmed nasser
// Copyright   : number step
// Description : http://acm.tju.edu.cn/toj/showp1233.html
//============================================================================
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
map<pair<int, int>, int> num;
void build() {
	int sum1 = 0, sum2 = 2;
	for (int i = 0, e = 2; i < 50000 && e < 500000; i++, e++) {
		num[make_pair(i, i)] = sum1;
		num[make_pair(e, i)] = sum2;
		if (i % 2 == 0) {
			sum1 += 1;
			sum2 += 1;
		} else {
			sum1 += 3;
			sum2 += 3;
		}
	}
}
int main() {
	build();
	int n, r, s;
	scanf("%d", &s);
	while (s--) {
		scanf("%d %d", &n, &r);
		if (r == 0 && n == 0)
			cout << "0" << endl;
		else {
			if (num[make_pair(n, r)] == 0)
				cout << "No Number" << endl;
			else
				cout << num[make_pair(n, r)] << endl;
		}
	}
	return 0;
}
