//http://www.spoj.com/problems/STREETR/	
#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORE(n,a,b) for(int n=a;n<b;n++)
int gcd(int a, int b) {
if (a == 0)
return b;
return gcd(b % a, a);
}
bool ch(vector< unsigned long long >numset,unsigned long long ll){
    FOR(i,0,numset.size()){
        if(ll == numset[i]){
            return false;
        }
    }
    return true;
}
int main(){
    vector< unsigned long long >numset;
    int many;
    scanf("%d",&many);
    unsigned long long mn = 0;
    unsigned long long sum = 0;
    vector< unsigned long long >num;
    int lll = 999999999;
    while(many--){
        unsigned long long tmp;
        scanf("%u",&tmp);
        if(mn == 0){
            mn = tmp;
        }else {
           num.push_back(tmp-mn);
           if(num.size()>1){
                lll = min(gcd(int(num[num.size()-1]),int(num[num.size()-2])),int(lll));
           }
           mn = tmp;
        }
    }
    FOR(i,0,num.size()){
        sum+=(num[i]/lll-1);
    }
    printf("%u",sum);
    return 0;
}

