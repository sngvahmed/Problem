// @Sep 13, 2014
// @CPY sngv ..... inc ARG.cpp
#include "bits/stdc++.h"
#include <functional>
#include <ext/numeric> // for power long long

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
typedef vector < string > vs;
typedef vector < int > vi;
typedef pair < int,vi > pi;
typedef pair < int,int > vp;
typedef pair < int,pair < int,int > > Hamada;

int main( ) {
#ifndef ONLINE_JUDGE
     freopen("test.in","rt",stdin);
#endif
     int n;
     scanf("%d",&n);
     string str;
     cin>>str;
     string strRes;
     strRes.resize((SZ(str)));
     int tmp=1;
     FO(i , 0 , n)
     {
          if(str [i]=='0'&&!tmp){
                strRes [i]='0';
          }
          else if((str [i]=='0'&&tmp)||(str [i]=='1'&&!tmp)){
                strRes [i]='1';
                tmp=0;
          }
          else if((str [i]=='1'&&tmp)){
                strRes [i]='0';
                tmp=1;
          }
     }
     tmp=0;
     FO(i , 0 , n)
              if(str [i]!=strRes [i]) tmp++;
     cout<<tmp<<endl;
     return 0;
}
