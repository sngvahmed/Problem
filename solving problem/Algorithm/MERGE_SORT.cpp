// Mar 13, 2014 MERGE_SORT.cpp
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
int arr[100001];
void Merge(int st1, int ed1, int st2, int ed2) {
	int sz = (ed2 - st2) + (ed1 - st1) + 2, s = st1;
	int arrtmp[sz];
	FO(i, 0, sz) {
		if (st2 > ed2 || (st1 <= ed1 && arr[st1] < arr[st2]))
			arrtmp[i] = arr[st1], st1++;
		else if (st1 > ed1 || (st2 <= ed2 && arr[st2] < arr[st1]))
			arrtmp[i] = arr[st2], st2++;
	}
	FO(i,0,sz)
		arr[s] = arrtmp[i], s++;
}
void Divide(int start, int end) {
	if (start == end)
		return;
	Divide(start, (end + start) / 2), Divide(((end + start) / 2) + 1, end);
	Merge(start, (end + start) / 2, ((end + start) / 2) + 1, end);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	int n;
	scanf("%d", &n);
	MMS(arr, 0);
	FO(i,0,n) {
		scanf("%d", &arr[i]);
	}
	Divide(0, n - 1);
	FO(i,0,n)
		cout << arr[i] << endl;
}
//@CPY::SNGV
