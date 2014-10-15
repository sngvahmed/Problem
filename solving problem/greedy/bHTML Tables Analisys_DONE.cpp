//============================================================================
// Author      : Ahmed nasser
// Version     : 1
// Copyright   : B. bHTML Tables Analisys
// Description : AC
//============================================================================
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
//<table><tr><td></td></tr></table>
void selection(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int w = i;
		for (int k = i + 1; k < n; k++) {
			if (arr[w] > arr[k])
				w = k;
		}
		swap(arr[w], arr[i]);
	}
}
int main() {
	int arrint[50000];
	int sz = -1;
	int e = -1;
	int y = -1;
	string st = "<table>", fn = "</table>", td = "<td>", tr = "<tr>", tdf =
			"</td>", trf = "</tr>";
	//<table><tr><td><table><tr><td></td><td></td></tr></table></td><td><table><tr><td></td></tr></table></td></tr></table>
	int arrret[500000];
	string s = "";
	int b = 0;
	vector<int> ss;
	while (true) {
		string x;
		cin >> x;
		FO(i,0,SZ(x)) {
			s += x[i];
			if (sz > y)
				arrint[e] = 0;
			if (s == tr)
				s = "";
			if (s == st)
				ss.push_back(0), sz++, s = "", e++;
			else if (s == td)
				ss[e]++, arrint[y]++, s = "";
			else if (s == fn) {
//				cout << ss[e] << endl;
				sz--, s = "", arrret[b] = ss[e], b++, arrint[y] = 0, ss.erase(
						ss.begin() + e), e--;
			} else if (s == tdf || s == trf)
				s = "";
			y = max(sz, y);
		}
		//<table><tr><td><table><tr><td><table><tr><td></td>
		//</tr></table></td></tr></table></td></tr></table>
		y = max(sz, y);
		if (sz == -1 && s == "")
			break;
	}
//	FO(i,0,ss.size())
//		cout << ss[i] << " ";
//	cout << endl;
	arrret[e] = arrint[0], e++;
	selection(arrret, b);
	FO(i,0,b)
		cout << arrret[i] << " ";
}
