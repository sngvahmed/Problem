#include "bits/stdc++.h"
#include <functional>

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
int n, m;
int arr[30];
void print(vi var) {
	sort(rall(var));
	FO(i , 0 , SZ(var)) {
		if (i != SZ(var) - 1)
			cout << var[i] << "+";
		else
			cout << var[i];
	}
	cout << endl;
}
void BUILD(int num, int tot, vi var) {
	for (int i = num; i >= 0; i--) {
		if (tot + arr[i] == n) {
			var.pb(arr[i]), print(var), var.erase(var.end() - 1);
		} else if (tot + arr[i] < n) {
			var.pb(arr[i]), BUILD(i, tot + arr[i], var), var.erase(
					var.end() - 1);
		}
	}
}
int main() {
	int num;
	cin >> num;
	n = num;
	FO(i , 0 , 30) {
		arr[i] = i + 1;
	}
	BUILD(num - 1, 0, vi());
}
