//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=36
#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORE(n,a,b) for(int n=a;n<b;n++)
unsigned int func(unsigned int num){
    unsigned int e = 1 ;
    while(num>1){
        if (num%2 == 0)
            num = num/2;
        else
            num = (num*3)+1;
        e++;
    }
    return e;
}
int main(){
    unsigned int x,y;
    while(cin >> x >> y){
        bool s = false;
        if ( x > y){
            swap(x,y); s=true;}
        unsigned int sum=0;
        for(int i=x;i<=y;i++){
            sum = max(func(i),sum);}
        if (s == false)
        cout << x << " " << y << " " << sum << endl;
        else
        cout << y << " " << x << " " << sum << endl;
        sum = 0;
    }
    return 0;
}

