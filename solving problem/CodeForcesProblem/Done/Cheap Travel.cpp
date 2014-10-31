// @Sep 12, 2014
// @CPY sngv ..... Cheap Travel.cpp
#include "bits/stdc++.h"
#include <functional>
#include <ext/numeric> // for power long long

using namespace std;

// a rubles
// m rides for b rubles

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
int n,m,a,b;
int getThemax( int sum,int tot ) {

     if(sum == 0) return tot;
     int tot1 = getThemax( sum - 1 , tot + a ),tot2 = 10000000;
     if(sum >= m)
     tot2 = getThemax( sum - m , tot + b );
     return min( tot1 , tot2 );

}

int main( ) {
#ifndef ONLINE_JUDGE
     freopen( "test.in" , "rt" , stdin );
#endif

     cin >> n >> m >> a >> b;

     int sum1 = a*n;
     int sum3 = (n/m)*b;
     int sum2 = sum3;
     if(n%m!=0){
          sum2 += (n%m)*a;
          sum3 += b;
     }

     cout << min(sum3 , min( sum1 , sum2 )) << endl;
//   cout << getThemax( n , 0 );

     return 0;
}
