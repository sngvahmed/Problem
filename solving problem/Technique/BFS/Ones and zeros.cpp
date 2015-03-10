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
int lvl = 11;

vector<pair<int, int> > que;
void bfs(int num) {
	queue<int> que;
	que.push(1);
	while (!que.empty()) {
		int sz = que.size();
		while (sz--) {
			int numb = que.front();
			que.push(numb * 10);
			que.push((numb * 10) + 1);
			if (numb % num == 0) {
				cout << numb << endl;
				return;
			}
			que.pop();
		}
	}
}
pair<string, int> BFS(int num) {
	que.push_back(make_pair(1, -1));
	FO(i,0,SZ(que)) {
		int number = que[i].first * 10;
		if (number >= num)
			number %= num;
		if (number == 0)
			return make_pair("0", i);
		que.push_back(make_pair(number, i));
		number = (que[i].first * 10) + 1;
		if (number >= num)
			number %= num;
		if (number == 0)
			return make_pair("1", i);;
		que.push_back(make_pair(number, i));
	}
}

string reverse(string num) {
	reverse(num.begin(), num.end());
	return num;
}
int main() {
//#ifndef ONLINE_JUDGE
//	freopen("test.in", "rt", stdin);
//	freopen("o.txt", "wt", stdout);
//#endif
	int n;
	scanf("%d", &n);
	while (n--) {
		int num;
		scanf("%d", &num);
		que.clear();
		pair<string, int> where = BFS(num);
		while (where.second != -1) {
			if (where.second % 2 == 1)
				where.first += '0';
			else
				where.first += '1';
			where.second = que[where.second].second;
		}
		cout << reverse(where.first) << endl;
	}
	return 0;
}
// @Copy Right To Ahmed Nasser
