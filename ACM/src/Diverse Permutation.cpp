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
#define SF(x) scanf("%d",&x)

int main() {
	int n, m;
	SF(n), SF(m);
	map<int, int> vis;
	int ini = 1, i = m - 1, s = 1, tot = n;
	while (true) {
		if (vis[ini] == 0) {
			vis[ini] = 1;
			n--;
			if (n == 0) {
				cout << ini;
				return 0;
			} else
				cout << ini << " ";
		}
		int tmp = (ini + (((i % m) + 1) * s));
		if (tmp <= tot && vis[tmp] == 0) {
			ini += (((i % m) + 1) * s);
		} else
			i++;
		if (ini == tot)
			s = -1;
	}
	return 0;
}
