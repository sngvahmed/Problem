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
bool vis[189][189];
int lvl = -1;
class BinaryCode {
//123210122
public:
	string Decod(string ret, string message) {
		if(message.size() == 1 && message == ret)return ret;
			else if (message.size() == 1) return "NONE";
		FO(i,0,SZ(message)) {
			int r;
			cout << ret << message[i] << " " << ret[i] << " " << endl;
			if (i == 0) {
				r = (message[0] - '0') - (ret[i] - '0');
			} else if (i == (SZ(message) - 1)) {
				if ((message[i] - '0') == ((ret[i] - '0') + (ret[i - 1] - '0')))
					break;
				else
					return "NONE";
			} else {
				r = (message[i] - '0') - ((ret[i] - '0') + (ret[i - 1] - '0'));
			}
			if (r > 1)
				return "NONE";
			ret += (r + '0');
		}
		FO(i,0,SZ(ret))
			if (ret[i] != '1' && ret[i] != '0')
				return "NONE";
		return ret;
	}
	vector<string> decode(string message) {
		vector<string> ret;
		ret.push_back(Decod("0", message));
		ret.push_back(Decod("1", message));
		return ret;
	}
};
