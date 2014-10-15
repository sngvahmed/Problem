// @Aug 22, 2014
// @CPY sngv ..... Pashmak and Garden.cpp 
#include "bits/stdc++.h"
#include <functional>

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
	 freopen( "test.in" , "rt" , stdin );
#endif
	 int x1,x2,y1,y2;
	 int xt1,xt2,yt1,yt2;
	 scanf( "%d%d%d%d" , &x1 , &y1 , &x2 , &y2 );
	 if(x1 == x2 && y1 != y2){
		  int dis = abs( y1 - y2 );
		  xt1 = x1 + dis,yt1 = y1,xt2 = x2 + dis,yt2 = y2;
	 }else if(y1 == y2 && x1 != x2){
		  int dis = abs( x1 - x2 );
		  xt1 = x1,yt1 = y1 - dis,xt2 = x2,yt2 = y2 - dis;
	 }else if(x1 != x2 && y1 != y2){
		  xt1 = x1,yt1 = y2,xt2 = x2,yt2 = y1;
	 }
	 vector < pair < int,int > > vec;
	 vec.pb( mp( x1 , y1 ) ),vec.pb( mp( x2 , y2 ) );
	 vec.pb( mp( xt1 , yt1 ) ),vec.pb( mp( xt2 , yt2 ) );
	 sort( all( vec ) );
	 if(abs( vec [0].F - vec [2].F ) == abs( vec [0].S - vec [1].S )){
		  cout << xt1 << " " << yt1 << " " << xt2 << " " << yt2 << endl;
	 }else cout << -1 << endl;
	 return 0;
}
