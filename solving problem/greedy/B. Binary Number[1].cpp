
//http://codeforces.com/problemset/problem/92/B
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <utility>
using namespace std;
#define FOR(i,a,b) for(long long  i=a;i<b;i++)
#define FORE(n,a,b) for(long long n=a;n>=b;n--)

int main(){
    string num;
    cin >> num;
    if (num == "1"){cout << 0; return 0;}
    unsigned long long count = 0;
    unsigned long long z = num.size()-1;
    while(true){
        if ( z <= 0)
            {break;}
        if(num[z] == '0'){count++;}
        else if (num[z] == '1'){
            count++;
            while(num[z]!='0'){
                if ( z == 0)
                    {count++; break;}
                count++;
                z--;
            }
            num[z] = '1';
            z++;
        }
        z--;
    }
    printf("%llu",count);
    return 0;
}

