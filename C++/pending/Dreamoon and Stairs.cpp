#include "bits/stdc++.h"
#include <functional>
#include <ext/numeric> 
using namespace std;

#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MMS(x, v) memset(x, v, sizeof(x))

int main() {

//	freopen("test.in", "rt", stdin);

	int n, m;
	scanf("%d%d", &n, &m);
	if (m == n) {
		cout << n << endl;
		return 0;
	}
	int numOfTwo = n / 2, numOfOne = n % 2;
	int total = numOfOne + numOfTwo;
	if (total % m == 0) {
		cout << total << endl;
		return 0;
	}
	if (total == m || total % m == 0) {
		cout << total << endl;
		return 0;
	}
	if (total < m) {
		int tmp = m - total;
		if (tmp <= numOfTwo) {
			cout << m << endl;
			return 0;
		}
	} else {
		int div = total / m;
		div++;
		int how = div * m;
		how = how - total;
		if (how <= numOfTwo) {
			cout << how + numOfTwo + numOfOne << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
