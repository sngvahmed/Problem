#include <iostream>
//http://www.codeforces.com/problemset/problem/221/A
#include <algorithm>
#include <string.h>
using namespace std;
int main(){
    int num;
    cin>>num;
    int sz = num-1;
    int arr[10000];
    int e = 0;
    while(num!=0){
        arr[e] = num;
        num--;
        e++;
    }
    e = 1;/*
    while(e < sz){
        int temp = arr[e];
        arr[e] = arr[sz-e + 1];
        arr[sz - e + 1] = temp;
        e++;
    }*/
    e = 0;
    cout<<arr[0]<<" ";
    for(int i=sz;i>0;i--)
        if(i!=1)
            cout<<arr[i]<<" ";
        else
            cout<<arr[i];
    return 0;
}
