// @Sep 30, 2014
// @CPY sngv ..... George and Accommodation.cpp 
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

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	int n;
	scanf("%d", &n);
	cout << "+------------------------+" << endl;
	int arr[4];
	int b = 0;
	arr[0] = arr[1] = arr[2] = arr[3] = 0;
	if (n == 4)
		arr[0] = 1, arr[1] = 1, arr[3] = 1, b = 1;
	else if (n == 3)
		arr[0] = 1, arr[1] = 1, b = 1;
	else if (n == 2)
		arr[0] = 1, arr[1] = 1;
	else if (n == 1)
		arr[0] = 1;
	else if (n > 4) {
		n -= 4;
		b = 1;
		if (n % 3 == 0) {
			arr[0] = 1 + n / 3, arr[1] = arr[0], arr[3] = arr[0];
		} else if (n % 3 == 1) {
			arr[0] = 1 + n / 3, arr[1] = arr[0], arr[3] = arr[0], arr[0]++;
		} else if (n % 3 == 2) {
			arr[0] = 1 + n / 3, arr[1] = arr[0], arr[3] = arr[0], arr[0]++, arr[1]++;
		}
	}
	FO(i , 0 , 4)
	{
		cout << "|";
		if (i == 2) {
			if (b == 1)
				cout << 'O';
			else
				cout << '#';
			cout << ".......................|" << endl;
			continue;
		}
		FO(j,0,22)
		{
			if (arr[i] > 0) {
				cout << "O.";
			} else
				cout << "#.";
			arr[i]--, j++;
		}
		if (i == 0)
			cout << "|D|)";
		else if (i == 3)
			cout << "|.|)";
		else if (i == 1)
			cout << "|.|";

		cout << endl;
	}
	cout << "+------------------------+" << endl;
	return 0;
}
