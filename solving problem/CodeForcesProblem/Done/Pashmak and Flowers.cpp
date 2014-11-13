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

typedef unsigned long long ull;

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	int n;

	scanf("%d", &n);

	vector<int> var(n);
	for (int i = 0; i < SZ(var); i++)
		scanf("%d", &var[i]);

	sort(all(var));
	if (var[0] == var[SZ(var) - 1]) {
		cout << 0 << " " << ull((ull) SZ(var) * (ull) (SZ(var) - 1)) / 2
				<< endl;
		return 0;
	}
	int countf = 0, countl = 0;
	int i = SZ(var) - 1;
	while (var[i] == var[SZ(var) - 1])
		i--, countl++;

	i = 0;
	while (var[i] == var[0])
		i++, countf++;

	cout << var[SZ(var) - 1] - var[0] << " " << ull(ull(countf) * ull(countl))
			<< endl;
	return 0;
}
