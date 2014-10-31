#include "bits/stdc++.h"
using namespace std;
#define FO(i, a, x) for(int i = a; i < (int)x; i++)
#define F first
#define S second
#define MMS(x, v) memset(x, v, sizeof(x))

int dip[] = { 0, 1, 0, -1 };
int djp[] = { 1, 0, -1, 0 };
int diq[] = { 0, 1, 0, -1 };
int djq[] = { 1, 0, -1, 0 };
int n, p;
int dp[1001];
int DP(int x) {
	if (dp[x])
		return dp[x];
	if (x == 0 || x == 1)
		return 1;
	int &tot = dp[x] = 0;
	if (x % 2 == 0)
		tot += DP(x / 2);

	FO(i , 1 , x+1) {
		if ((x - i) % 2 == 0)
			tot += DP((x - i) / 2);
	}
	return tot;
}
int main() {
	cin >> n;
	p = 0;
	MMS(dp, 0);
	while (n--) {
		int num;
		cin >> num;
		cout << ++p << " " << DP(num) << endl;
	}
}
