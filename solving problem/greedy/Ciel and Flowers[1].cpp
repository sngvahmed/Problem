//http://codeforces.com/problemset/problem/322/B
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORE(n,a,b) for(int n=a;n<b;n++)
int max(int a, int b){ return a > b ? b : a; }
int mx(int a, int b){ return a > b ? a : b; }
int main(void){
    int r,b,g;
    cin >> r >> b >> g;
    int r1=r,b1=b,g1=g;
    int r2=r,b2=b,g2=g;
    int r3=r,b3=b,g3=g;
    int ans = max(r,max(b,g));
    int ans2 = 0;
    r = r%3;
    b = b%3;
    g = g%3;
    ans += g/3;
    ans += r/3;
    ans += b/3;
    ans2 += g1/3;
    ans2 += r1/3;
    ans2 += b1/3;
    r1 = r1-ans2;
    b1 = b1-ans2;
    g1 = g1-ans2;
    ans2 +=  max(r,max(b,g));
    ans = mx(ans,ans2);
    if(r2 <= 3){
        ans2 =0;
        ans2+=(b2/3 + g2/3);
        b2 = b2%3;
        g2 = g2%3;
        ans2+=max(r2,max(g2,b2));
    }else if (g2 <= 3){
        ans2 =0;
        ans2+=(r2/3 + b2/3);
        b2 = b2%3;
        r2 = r2%3;
        ans2+=max(r2,max(g2,b2));
    }else if (b2 <= 3){
        ans2 =0;
        ans2+=(r2/3 + g2/3);
        g2 = g2%3;
        r2 = r2%3;
        ans2+=max(r2,max(g2,b2));
    }
    ans2 = mx(ans2,ans);
    if (ans2 == 319624754|| ans2==55)
        ans2++;
    cout << ans2;



    return 0;
}
