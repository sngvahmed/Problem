//http://www.spoj.com/problems/TRANCLS/
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <utility>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORE(n,a,b) for(int n=a;n>=b;n--)
unsigned int d = 0;
/*
string sUm(string num){
    d = 1;
    FORE(n,num.size()-1,0)
        if(num[n] == '0'){num[n]='1'; return num.substr(0,n+1);}
        else {d++;}
    return "1";
}
string Div(string num){
    d = 0;
    //cout << num << endl;
    for(unsigned int n = num.size()-1; n>=0 ;n--)
        if(num[n] == '0')d++;
        else break;
    num.erase(num.size()-d,num.size()-1);
    return num;
}
int main(){
    string num;
    cin >> num;
    unsigned int count = 0;
    while( num != "1"){
        if (num[num.size()-1] == '0')num = Div(num),count+=(d-1);
        else num = sUm(num),count+=(d-1);
        count++;
    }
    printf("%d",count);
    return 0;
}*/
int main(){
    int x,y;
    int c = 0;
    scanf("%d",&x);
    while(x--){
        int arr1[1000];
        int arr2[1000];
        int size = 0;
        c++;
        int y;
        scanf("%d",&y);
        while(y--){
            int temp1,temp2;
            scanf("%d %d",&temp1,&temp2);
            arr1[size] = temp1;
            arr2[size] = temp2;
            size++;
        }
        int sum = 0;
        for(int i=0;i<size;i++){
            for(int n = 0; n<size ;n++){
                if(i!=n && arr2[i] == arr1[n]){
                    bool o = false;
                    for(int e = 0; e<size ;e++){
                        if ( arr1[e] == arr1[i] && arr2[e] == arr2[n])
                            {o = true;  break;}
                    }
                    if (o == false)
                        {sum++; arr1[size] = arr1[i]; arr2[size]=arr2[n];  size++;}
                }
            }
        }
        //FOR(i,0,size)cout << arr1[i]<<arr2[i] << " ";
        cout << "Case #" << c << ": " << sum << endl;
    }

}

