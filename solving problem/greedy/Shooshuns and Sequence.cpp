// May 20, 2014 , Shooshuns and Sequence.cpp 
#include "bits/stdc++.h"
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
typedef pair<int, vi> vp;
map<int, vi> var;
int n, m;
vi arr;

bool Equality() {
	if (arr.size() == 1)
		return 1;
	FO(i , 0 , n-1)
		if (arr[i] != arr[i + 1])
			return 0;
	return 1;
}
int numberVarious() {
	int n = 0;
	FO(i , 0 , n-1)
		if (arr[i] != arr[i + 1])
			n++;
	return n;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	scanf("%d%d", &n, &m);
	arr.resize(n);
	FO(i , 0 , n)
		scanf("%d", &arr[i]);

	for (int i = m - 1; i < SZ(arr) - 1; i++)
		if (arr[i] != arr[i + 1]) {
			cout << -1 << endl;
			return 0;
		}
	int i = m - 1;
	while (arr[i] == arr[m - 1] && i >= 0) {
		i--;
	}
	cout << i + 1 << endl;

	return 0;
}
// CPY @SNGV
