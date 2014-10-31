//============================================================================
// Author      : Ahmed nasser
// Version     : 1
// Copyright   : COPY RITHT To :: ahmed nasser saleh
// Description : All Implention Important Code
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
class TheBrickTowerMediumDivTwo {
public:
	vector<int> find(vector<int> heights) {
        vi ret,num(SZ(heights));
        FO(i,0,SZ(heights))
            num[i]=i;
        int tmp = 90000000;
        do{
            int t = 0;
            FO(i,0,SZ(heights)-1)
                t+=max(heights[num[i]],heights[num[i+1]]);
            if(t<tmp)tmp=t,ret=num;
        }while(next_permutation(all(num)));
        return ret;
	}
};
