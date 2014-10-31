//http://codeforces.com/problemset/problem/155/A
#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORE(n,a,b) for(int n=a;n<b;n++)
int main(){
    int sze ,temp = -1,tm,tl, sum = 0;
    cin >> sze;
    cin >> temp;
    tm = tl = temp;
    sze--;
    while(sze--){
        cin >> temp;
        if (temp>tm)sum++,tm = temp;
        if (temp<tl)sum++,tl = temp;
    }
    cout << sum;
    return 0;

}
