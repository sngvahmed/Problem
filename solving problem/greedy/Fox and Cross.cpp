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
int di[] = { 0, 1, 1, 1, 2 }, dj[] = { 0, 1, -1, 0, 0 };
char arr[101][101];
int n, m = 0;
bool validate(int i, int j) {
	return (i >= 0 && j >= 0 && i < n && j < n && arr[i][j] == '#') ? 1 : 0;
}
int DFS(int i, int j) {
	if (arr[i][j] == '.')
		return 0;
	FO(r,0,4)
		if (validate(i + di[r], j + dj[r]) == 0)
			return 0;
	FO(r,0,5)
		arr[i + di[r]][j + dj[r]] = '.';
	return 1;
}
bool validALL() {
	FO(i,0,n) {
		FO(j,0,n) {
			if(arr[i][j] == '#')return 0;
		}
	}
	return 1;
}
string Generate() {
	int con = 0;
	FO(i,0,n)
		FO(j,0,n)
			con += DFS(i, j);
	if (validALL())
		return "YES";
	else
		return "NO";
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
//	freopen("o.txt", "wt", stdout);
#endif
	scanf("%d", &n);
	FO(i,0,n)
		cin >> arr[i];
	int cnt = 0;
	FO(i,0,n)
		FO(j,0,n)
			if (arr[i][j] == '#')
				cnt++;
	if (cnt % 5 == 0)
		cout << Generate() << endl;
	else
		cout << "NO" << endl;
	return 0;
}
