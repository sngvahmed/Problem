//============================================================================
// Author      : Ahmed nasser
// Version     : 1
// Copyright   : COPY RITHT To :: ahmed nasser saleh
// Description : All Implention Important Code
//============================================================================
#include <cstring>
#include <string.h>
#include <map>
#include <deque>296
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
class OlympicCandles {
public:
	vector<int> selection(vector<int> arr) {
		int n = arr.size();
		for (int i = 0; i < n; i++) {
			int w = i;
			for (int k = i + 1; k < n; k++) {
				if (arr[w] < arr[k])
					w = k;
			}
			swap(arr[w], arr[i]);
		}
		return arr;
	}
	int numberOfNights(vector<int> cd) {
		int sum = 0;
		while (true) {
			cout << "befour";
			cd = selection(cd);
			FO(i,0,cd.size())
				cout << cd[i] << " ";
			cout << endl;
			FO (i,0,min(SZ(cd),sum+1))
				if (cd[i])
					cd[i]--;
				else
					return sum;
			sum++;
			cout << "after";
			FO(i,0,cd.size())
				cout << cd[i] << " ";
			cout << endl;
			if (sum == SZ(cd))
				return sum;
		}
	}
};
