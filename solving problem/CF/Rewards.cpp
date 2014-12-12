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
	int numcup = 0 , numm = 0;
	for (int i = 0; i < 3; i++) {
		int tmp ; cin >> tmp; numcup += tmp;
	}
	for (int i = 0; i < 3; i++) {
		int tmp ; cin >> tmp; numm += tmp;
	}
	int n;
	cin >> n;
	while(n--){
		if(numcup > 0)numcup -=5;
		else if(numm > 0)numm -=10;
	}
	if(numm <= 0 && numcup <=0){cout << "YES" << endl;}
	else cout << "NO" << endl;
	return 0;
}
