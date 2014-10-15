//http://codeforces.com/problemset/problem/5/B
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
int main(){
    #ifndef ONLINE_JUDGE
        //freopen("test.in", "rt", stdin);
          //freopen("o.txt", "wt", stdout);
    #endif
    string text;
    vector<string>tx;
    int d = 1;
    /*while(d--){
        //cin >> text;
        getline(cin,text);
        tx.push_back(text);
    }*/
    while(getline(cin,text)){
        tx.push_back(text);
    }
    int co = tx.size();
    int sz = -1;
    while(co--){
        int size = tx[co].size();
        sz = max(size,sz);
    }
    //cout << sz << endl;
    co = 1;
    FOR(i,0,sz+2)cout<<"*";
    cout << endl;
    for(int n=0;n<tx.size();n++){
        cout << "*";
        int space = sz - tx[n].size();
        if (space % 2 == 0){
            FOR(i,0,space/2)cout<<" ";
            cout << tx[n];
            FOR(i,0,space/2)cout<<" ";
        }else {
            if(co%2==0){
                co++;
                FOR(i,0,space/2+1)cout<<" ";
                cout << tx[n];
                FOR(i,0,space/2)cout<<" ";
            }else {
                co++;
                FOR(i,0,space/2)cout<<" ";
                cout << tx[n];
                FOR(i,0,space/2+1)cout<<" ";
            }
        }
        cout << "*";
        cout << endl;
    }
    FOR(i,0,sz+2)cout<<"*";
    return 0;
}

