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
int n, m;
int CountOfInt(int num) {
	int ret = 0;
	while (num) {
		if (num & 1)
			ret++;
		num >>= 1;
	}
	return ret;
}
int CountOfIntModify(int num) {
	int ret = 0;
	while (num) {
		num &= (num - 1);
		ret++;
	}
	return ret;
}
int GetBit(int num, int Indx) {
	return (num >> Indx) & 1;
}
int SetBit1(int num, int indx) {
	return num | (1 << indx);
}
int SetBit0(int num, int indx) {
	return num & ~(1 << indx);
}
int flipBit(int num, int indx) {
	return num ^ (1 << indx);
}
void printNumber(int n, int len) {
	if (!len) {
		cout << endl;
		return;
	}
	printNumber(n >> 1, len - 1);
	cout << (n & 1);
}
void GetAllSubset(int num) {
	for (int subMsk = num; subMsk; subMsk = (subMsk - 1) & num) {
		printNumber(subMsk, 32);
		cout << endl;
	}
}
void changeString() {

}
int main() {
	int x, y;
	cin >> x >> y;
	cout << "X = " << x + y << endl;
	return 0;
}
// @Copy Right To Ahmed Nasser
