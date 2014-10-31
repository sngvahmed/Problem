#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <sstream>
#include <deque>
#include <utility>
#include <bitset>
#include <ext/hash_map>

using namespace std;
using namespace __gnu_cxx;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,a,b) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define oo 2e9
#define MAX 1001
#define sz(v) (int)v.size()
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define iter(it,s) for(it=s.begin();it!=s.end();it++)
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define mem(s,v) memset(s,v,sizeof(s))

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

int vis[MAX];
int memo[MAX];
int dx[] = { };
int dy[] = { };

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	//    freopen("o.txt", "wt", stdout);
#endif
	int arr[44723];
	int c = 0, x = 2;
	// pre-calculation for all billiard numbers
	while (true) {
		int f = (x * (x - 1)) / 2;
		arr[c++] = f;
		x++;
		// 1e9 == 10^9
		if (f >= 1e9)
			break;
	}
	int a, b, cs = 1;
	while (scanf("%d%d", &a, &b) && a && b) {
		int res = 0;
		// for all billiard numbers ...
		FOR (i , 0 , 44723) {
			if (arr[i] > b)
				break;
			// .. find a number within the range and check if it's a perfect square or not
			if (arr[i] + 1 > a && arr[i] + 1 < b) {
				int n = sqrt(arr[i] + 1);
				if (n * n == arr[i] + 1)
					res++;
			}
		}
		printf("Case %d: %d\n", cs++, res);
	}
	return 0;
}
