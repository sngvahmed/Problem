#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
#include <memory.h>
#include <climits>
#include <math.h>

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
int main() {
	int n;
	scanf("%d", &n);
	int arr[111][111];
	bool Ret[111];
	FO(i,1,n+1) {
		int tmp = 0;
		scanf("%d", &tmp);
		while (tmp--) {
			int m;
			scanf("%d", &m);
			arr[i][m] = 1;
		}
	}
	memset(Ret, 1, sizeof Ret);
	FO(i,1,n+1) {
		FO(j,1,n+1) {
			if (i != j) {
				bool ch = 1;
				FO(e , 1 , 101) {
					cout << arr[i][e] << " " << !arr[j][e] << " " << i << " "
							<< j << " " << e << endl;
					if (arr[i][e] && !arr[j][e]) {
						ch = false;
						break;
					}
				}
				if (ch)
					Ret[j] = 0;
			}
		}

	}
	FO(i,1,n+1) {
		if (Ret[i])
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
	//system("pause");
}

