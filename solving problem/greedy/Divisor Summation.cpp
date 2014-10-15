//http://www.spoj.com/problems/DIVSUM/
#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <set>
#include<math.h>
using namespace std;
int primes[500000] ;
unsigned long long int SumOfDivisors(int num){
    int sum=0;
    for(int i=1; i*i<=num; i++)
        sum += (num%i)? 0 : ((i*i==num)? i : i+num/i);
    return sum;
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
    unsigned long long int num;
    scanf("%llu",&num);
    printf("%llu \n",SumOfDivisors(num)-num);
    }
    return 0;
}


