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

int a, b, c;
int tot() {
	int mx = -1;
	mx = max(mx, (a + b) * c);
	mx = max(mx, (b + c) * a);
	mx = max(mx, a + c + b);
	mx = max(mx, a * c * b);
	return mx;
}

int main() {

	SF(a), SF(b), SF(c);
	cout << tot() << endl;
	return 0;
}
