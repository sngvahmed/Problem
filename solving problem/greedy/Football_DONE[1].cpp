#include <iostream>
#include <conio.h>
#include <algorithm>
using namespace std;

string pin[10][2];
void sort(string pin[10][2], int COLS, int ROWS);
int main()
{
    string num;
    int e = 1;
    cin>>num;
    int con = 1;
    while(e <= num.size()-1){
        if(num[e] == num[e-1])
            con++;
        else
            con = 1;
        e++;
        if(con >= 7){
            cout<<"YES";
            return 0;
        }
    }
//    00100110 1 1 1 1 1 1 1 01
    cout<<"NO";
return 0;
}
