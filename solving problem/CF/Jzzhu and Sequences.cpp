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
#define SF(x) scanf("%d" , &x)

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int x = 10000, y = 1000000000, z = 0, n;
	cin >> x >> y >> n;
	int arr[6];
	arr[0] = x, arr[1] = y;
	for (int i = 2; i < 6; i++)
		z = y - x, x = y, y = z, arr[i] = z;
	int indx = (n % 6) - 1;
//	cout << arr[indx] << endl;
	if (indx < 0)
		indx += 6;
	while (arr[indx] < 0)
		arr[indx] += 1000000007;
	cout << arr[indx] % 1000000007 << endl;
	return 0;
}
