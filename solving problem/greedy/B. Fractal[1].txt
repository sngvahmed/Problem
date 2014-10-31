//============================================================================
// Author      : Ahmed nasser
// Version     : 1
// Copyright   : B. Fractal
// Description : http://codeforces.com/problemset/problem/36/B
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
int main(){

	freopen("input.txt","r",stdin);
#ifndef LocalHost
    freopen("output.txt","w",stdout);
#endif
    int x,y;
    scanf("%d %d",&x,&y);
    string ss="";
    FOR(i,x)ss+='*';
    vector<string>tmp1(x);
    int sz = 1;
    for(int e=0;e<y;e++)sz = sz*x;
    vector<string> ret(sz);
    FOR(e,x){
        string tm;
        cin >> tm;
        tmp1[e]=tm;
        ret[e]=tm;
    }
    for(int i=x;i<sz;i++)
        ret[i] = "";
    int yy = 0;
    int q = x;
    FOR(i,y-1){
        yy = 0;
        int szz = ret[0].size();
        for(int e=0;e<q;e++){
            for(int r=0;r<q;r++){
                if(ret[e][r]=='.'){
                    for(int n=0;n<x;n++){
                        ret[n+yy]+=tmp1[n];
                    }
                }
                else if(ret[e][r]=='*'){
                    for(int n=0;n<x;n++){
                            ret[n+yy]+=ss;
                    }
                }
            }
            yy += x;
        }
        for(int qq = 0;qq<q;qq++)
            ret[qq].erase(ret[qq].begin(),ret[qq].begin()+q);
        q = q*x;
    }
    for(int i=0;i<ret.size();i++)
        if(i<ret.size()-1)
            cout << ret[i] << endl;
        else
            cout << ret[i];
    return 0;
}
//***********  easy solution work but very slow :/ ***********************************
/*
//*************************
// vecrsion :2
//*************************
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
int main(){

	freopen("input.txt","r",stdin);
#ifndef LocalHost
    freopen("output.txt","w",stdout);
#endif
  int x,y;
    cin >> x >> y;
    string ss="";
    FOR(i,x)ss+='*';
    vector<string>tmp1;
    vector<string>tmp2;
        FOR(e,x){
        string tm;
        cin >> tm;
        tmp1.push_back(tm);
        tmp2.push_back(ss);
    }
    vector<string> ret = tmp1;
    FOR(i,y-1){
        vector<string>re;
        for(int e=0;e<ret.size();e++){
            FOR(t,x)re.push_back("");
            for(int r=0;r<ret[e].size();r++){
                int sz = re.size();
                if(ret[e][r]=='.'){
                    for(int n=0;n<x;n++){
                        re[n+sz-x]+=tmp1[n];
                    }
                }
                if(ret[e][r]=='*'){
                    for(int n=0;n<x;n++){
                            re[n+sz-x]+=tmp2[n];
                    }
                }
            }
        }
        ret = re;
    }
    for(int i=0;i<ret.size();i++)
            cout << ret[i] << endl;
    return 0;
}
*/
