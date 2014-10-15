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
int di[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dj[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
string ret = "ABCDEF ";
int lvl = -1;
//6 2 SULTAN
map<char, int> vis;
string str;
int BFS(int sz, int r) {
	int count = 0;
	queue<char> que;
	FO(i,0,r) {
		if (vis[str[i]] == 1)
			count++;
		if (que.size() == sz) {
			vis[que.front()] = 0;
			que.pop();
			que.push(str[i]);
			vis[str[i]] = 1;
		} else {
			que.push(str[i]);
			vis[str[i]] = 1;
		}
	}
	return count;
}
int BF(int sz, int r) {
	int count = 0;
	FO(i,0,r) {
		bool ch = 0;
		int sztm = sz, j = i;
		while (sztm > 0 && j >= 0) {
			j--, sztm--;
			if (str[i] == str[j]) {
				ch = 1;
				break;
			}
		}
		if (ch)
			count++;
	}
	return count;
}
int main() {
	int n;
	cin >> n;
	int co = 0;
	while (n--) {
		vis.clear();
		int x, r;
		cin >> x >> r >> str;
		cout << "Case " << ++co << ": " << BF(r, x) << endl;
	}
	return 0;

}
