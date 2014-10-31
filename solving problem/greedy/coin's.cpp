//http://codeforces.com/problemset/problem/58/B
#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORE(n,a,b) for(int n=a;n<b;n++)
bool primes[1000000] ;
//int arr[1000000];
//int e = 0;
void initPrimes(){
    memset( primes , true , sizeof(primes) ) ;
    primes[0]=primes[1]=false ;
    for( int i=2 ; i<=1000000 ; i++ ){
	    if( primes[i] ){
	    	for( int j=2 ; i*j<=1000000 ; j++ )
	    		primes[i*j]=false ;
		}
    }
}
int main(){
    initPrimes();
  //  FOR(i,0,e)cout << arr[i] << " ";
    int num;
    cin >> num;
    if ( num == 1)
    {
        cout << 1;
        return 0;
    }
    while(num != 1){
        cout << num << " ";
        if ( primes[num])
            {num = 1 ;break;}
        for(int i=2;i<=1000000;i++)
            if ( num % i == 0){num = num/i; break;}
    }
    cout << num;

}
