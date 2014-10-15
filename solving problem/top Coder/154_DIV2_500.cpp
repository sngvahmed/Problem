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
map<char, char> BL;
class SuperRot {
public:
	void Build() {
		char st = 'a', ch = 'n';
		while (st != 'n')
			BL[st] = ch, ch++, st++;
		st = 'n', ch = 'a';
		while (int(st) != int('z') + 1)
			BL[st] = ch, ch++, st++;
		st = 'A', ch = 'N';
		while (st != 'N')
			BL[st] = ch, ch++, st++;
		st = 'N', ch = 'A';
		while (int(st) != int('Z') + 1)
			BL[st] = ch, ch++, st++;
		st = '0', ch = '5';
		while (st != '5')
			BL[st] = ch, ch++, st++;
		st = '5', ch = '0';
		while (int(st) != int('9') + 1)
			BL[st] = ch, ch++, st++;
	}
	string decoder(string message) {
		Build();
		FO(i,0,SZ(message)) {
			if ((message[i] >= 'a' && message[i] <= 'z')
					|| (message[i] >= 'A' && message[i] <= 'Z')
					|| (message[i] >= '0' && message[i] <= '9')) {
				message[i] = BL[message[i]];
			}
		}
		return message;
	}
};
