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

bool vis[189][189];
int n = 0, m = 0, I = 0, Case = 1;
char arr[201][201];

void fill() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = '.';
		}
	}

}
void print() {

	cout << "Scenario #" << Case++ << ":" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}

}
int main() {

#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	//  freopen("o.txt", "wt", stdout);
#endif

	string dir = "";
	int moves = 0;

	while (cin >> n >> m >> I && m != 0 && I != 0 && n != 0) {
		int curx = 0, cury = 0;
		fill();
		for (int i = 0; i < I; i++) {
			cin >> dir >> moves;

			if (dir == "South") {

				for (int x = 0; x < moves; x++) {
					if (arr[curx][cury] == '.')
						arr[curx][cury] = '|';
					else
						arr[curx][cury] = '+';
					curx++;
				}
			} else if (dir == "East") {

				for (int x = 0; x < moves; x++) {
					if (arr[curx][cury] == '.')
						arr[curx][cury] = '-';
					else
						arr[curx][cury] = '+';
					cury++;
				}

			} else if (dir == "North") {

				for (int x = 0; x < moves; x++) {
					if (arr[curx][cury] == '.')
						arr[curx][cury] = '|';
					else
						arr[curx][cury] = '+';
					curx--;
				}

			} else {

				for (int x = 0; x < moves; x++) {
					if (arr[curx][cury] == '.')
						arr[curx][cury] = '-';
					else
						arr[curx][cury] = '+';
					cury--;
				}

			}
			arr[curx][cury] = '+';

		}
		print();
	}
}
// @Copy Right To Ahmed Nasser
