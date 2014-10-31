//http://www.spoj.com/problems/SHAHBG/
//coin's
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
int fins(vector<int>s,int t,int b,int e){
    if (s[(b+e)/2] == t)
        return b+e;
    if (s[(b+e)/2] > t)
        return fins(s,t,(b+e)/2+1,e);
    else if (s[(b+e)/2]<t)
        return fins(s,t,b,(b+e)/2-1);

}
int fin(vector<int>s,int t,int b,int e){
    FOR(i,0,s.size()) if (t == s[i]) return i;
    return -1;
}
int main(){
   int num;
   vector<int>sum;
   cin >> num;
   int g = 0;
   bool arr[20001] = {0};
   while (num--){
        int temp ;
        cin >> temp;
        arr[temp] = 1;
        if (temp == 0 && arr[temp+1] != 1)
            g++,arr[temp]=1;
        else if (temp == 20000 && arr[temp-1] != 1)
            g++,arr[temp]=1;
        else if (arr[temp-1] == 1 && arr[temp+1] ==1)
            g--,arr[temp]=1;
        else if (arr[temp-1] != 1 && arr[temp+1] !=1)
            g++,arr[temp]=1;
        cout << g <<endl;
   }
    cout << "Justice" << endl;
}
