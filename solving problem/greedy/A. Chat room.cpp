http://codeforces.com/problemset/problem/58/A
#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORE(n,a,b) for(int n=a;n<b;n++)
unsigned int sum = 0;
int main(){
    string s;
    bool c1,c2,c3,c4,c5,c6;
    c1 = c2 = c4 = c3 = c5 = false;
    cin >> s;
    int c = 0;
    FOR(i,0,s.size()){
        //cout << c1 << c2 << c3 <<c4 << c5 << endl;
        if (s[i] == 'h' && c2 == false && c3 == false && c4 == false && c5 == false && c1 == false )
            c1 = true;
        if (c1 == true && c2 == false && c3 == false && c4 == false && c5 == false && s[i] == 'e')
            c2 = true;
        if (c2 == true && c1 == true && c3 == false && c4 == false && c5 == false && s[i] == 'l' && c == 0)
            c3 = true , c = 1;
        if (c3 == true && c1 == true && c2 == true && c4 == false && c5 == false && s[i] == 'l' && c != 1)
            c4 = true;
        if (c4 == true && c3 ==true &&  c2 ==true && c1 == true && c5 == false && s[i] == 'o')
            c5 = true;
        if ( c == 1)
             c = 0;
    //cout << c1 << c2 << c3 <<c4 << c5 << endl;
    }
    if ( c4== true && c3 ==true &&  c2 ==true && c1 == true && c5 == true )
        cout << "YES";
    else
        cout << "NO";

}
