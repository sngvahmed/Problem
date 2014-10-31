//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=825
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <utility>
#include <memory.h>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <numeric>
#include <functional>
#include <assert.h>

using namespace std;
int c = 0;
int e = 0;
map<int,int>ss;
map<int,int>sd;
int arr[1000001];
int err[1000001];
bool primes[1000001] ;
void initPrimes(){
    memset( primes , true , sizeof(primes) ) ;
    primes[0]=primes[1]=false ;
    for( int i=2 ; i<=1000000 ; i++ ){
	    if( primes[i] ){
			arr[e] = i;
			e++;
	    	for( int j=2 ; i*j<=1000000 ; j++ )
	    		primes[i*j]=false ;
		}
    }
}
int ttt(int n){
	//cout << arr[3];
	//cin.get();
    for(int i=0 ;  arr[i+1]<n ; i++)
        if(n%arr[i] == 0)
            return arr[i];
}
void tt(int n,int r){
	//cout<<"ahmed :: "<< n << endl;
    if(n == 1 || n == 0)
        return ;
    if(primes[n]){
        c++;
        return;
    }else{
        tt(ttt(n),r++);
        tt(n/ttt(n),r++);
    }
}
void it(int n){
    //cout<<n<<endl;
    //cin.get();
    for(int i=2;i<=n;i++){
		tt(i,0);
		ss[i] = c;
    }
}
void add(){
	err[0] = 1;
	for(int i=1;i<=1000000;i++){
		//cout<< "GET " << i << endl;
		tt(i,0);
		//cout<<"WR"<<endl;
		err[i] = err[i-1] + c;
		c = 0;
	}
}
int main(){
    initPrimes();
    add();
	int n;
	while(cin>>n){
		cout<<err[n]-1<<endl;
	    c = 0;
	}

}
