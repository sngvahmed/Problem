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
vector<int> v1(3), v2(3);
bool solve(vector<int> v1, vector<int> v2) {
	sort(v2.begin(), v2.end());
	int cnt;
	do {
		cnt = 0;
		if (v2[0] > v1[0])
			cnt++;
		if (v2[1] > v1[1])
			cnt++;
		if (v2[2] > v1[2])
			cnt++;
		if (cnt < 2)
			return false;
	} while (next_permutation(v2.begin(), v2.end()));
	return true;
}

int main() {
	scanf("%d %d %d %d %d", &v1[0], &v1[1], &v1[2], &v2[0], &v2[1]);
	while (v1[0]) {
		sort(all(v1));
		bool vis[53];
		MMS(vis,0), vis[v1[0]] = vis[v1[1]] = vis[v1[2]] = vis[v2[0]] =
				vis[v2[1]] = true;
		int ret = -1;
		for (int i = 1; i <= 52; i++) {
			if (!vis[i]) {
				v2[2] = i;
				if (solve(v1, v2)) {
					ret = i;
					break;
				}
			}
		}
		printf("%d\n", ret);
		scanf("%d %d %d %d %d", &v1[0], &v1[1], &v1[2], &v2[0], &v2[1]);
	}
}
