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

	long long num;
	cin >> num;

	int count = 0;
	for (int i = 1; i < 1000; i++) {
		if (((num + i) % 3))
			continue;
		long long numtot = (num + i) / 3;
		long long sum = i;
		sum = (sum + 1) * (sum);
		sum /= 2;
		if (numtot >= sum)
			count++;
		else if (sum > numtot)
			break;
	}
	cout << count << endl;
	return 0;
}
