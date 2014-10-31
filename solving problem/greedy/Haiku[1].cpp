#include <iostream>

using namespace std;
char arr[] =  {'a', 'e', 'i', 'o' ,'u'};
bool find(char x){
    for(int i=0;i<5;i++)if(arr[i] == x)return true;
    return false;
}
int main()
{
    string x1 , x2 , x3;
    getline(cin,x1);
    getline(cin,x2);
    getline(cin,x3);
    int tmp = 0;
    for(int i=0;i<x1.size();i++)if(find(x1[i]))tmp++;
    if(tmp!=5){cout << "NO"; return false;}
    tmp = 0;
    for(int i=0;i<x2.size();i++)if(find(x2[i]))tmp++;
    if(tmp!=7){cout << "NO"; return false;}
    tmp = 0;
    for(int i=0;i<x3.size();i++)if(find(x3[i]))tmp++;
    if(tmp!=5){cout << "NO"; return false;}
    cout << "YES";
    return 0;
}
