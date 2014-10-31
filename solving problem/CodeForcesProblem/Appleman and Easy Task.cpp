// @Sep 13, 2014
// @CPY sngv ..... Appleman and Easy Task.cpp 
#include "bits/stdc++.h"
#include <functional>
#include <ext/numeric> // for power long long 

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
typedef pair<int, vi> pi;
typedef pair<int, int> vp;
typedef pair<int, pair<int, int> > Hamada;
char str[105][105];
int sum[105][105];
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	int n;
	cin >> n;
	FO(i , 1 , n+1)
		FO(j , 1 , n+1)
			cin >> str[i][j];

	FO(i , 1 , n+1)
		FO(j , 1 , n+1)
		{
			if (str[i][j] == 'o')
				sum[i - 1][j]++, sum[i + 1][j]++, sum[i][j - 1]++, sum[i][j + 1]++;
		}
	FO(i , 1 , n+1)
		FO(j , 1 , n+1)
		{
			if ((sum[i][j]) % 2 != 0) {
				cout << "NO";
				return 0;
			}
		}
	cout << "YES";
	return 0;
}
