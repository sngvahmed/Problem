//http://codeforces.com/problemset/problem/3/A
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    /*a8
    h1*/
    string x,y;
    cin >> x >> y;
    vector<string>ret;
    while(x != y){
        string tmp = "";
        if(x[0] < y[0]){
            tmp += 'R';
            x[0] = int(x[0])+1;
        }else if (x[0] > y[0]){
            tmp += 'L';
            x[0] = int(x[0])-1;
        }
        if(x[1] < y[1]){
            tmp += 'U';
            x[1] = int(x[1])+1;
        }else if (x[1] > y[1]){
            tmp += 'D';
            x[1] = int(x[1])-1;
        }
        ret.push_back(tmp);
    }
    cout << ret.size() << endl;
    for(int i=0;i<ret.size();i++)
        cout << ret[i] << endl;
    return 0;
}
