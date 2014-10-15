//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=9
//http://ideone.com/WGakse
#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
#include <memory.h>
#include <climits>

using namespace std;

#define FO(i, a, x) for(int i = a; i < (int)x; i++)
#define FOR(i, x) FO(i, 0, x)
#define RO(i, a, x) for(int i = a; i >= x; i--)
#define ROF(i, x) for(int i = x; i >= 0; i--)
#define FORIT(it, x) for(typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define FOUND(s, x) find(all(s), x) != s.end()
#define NOTFOUND(s, x) find(all(s), x) == s.end()
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MMS(x, v) memset(x, v, sizeof(x))
#define SQ(x) (x) * (x)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<string> vs;
typedef vector<int> vi;

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
struct user{
    string name;
    int number;
};
vector<user>x;
user makeit(string num,int m){
    user u1;
    int i;
    u1.name = "",u1.number=0;
    for(i=0 ; i<num.size() ; i++){
        if((num[i]<='Z'&&num[i]>='A')||(num[i]>='a'&&num[i]<='z'))
            {u1.name+=tolower(num[i]); break;}
    }
    string emp = "";
    for(i = num.size()-1 ; i>=0 ; i--){
        if((num[i]<='Z'&&num[i]>='A')||(num[i]>='a'&&num[i]<='z'))
            {emp+=tolower(num[i]); }
        if(num[i]==' '&&emp!=""){
            break;
        }
    }
    //cout << emp << endl;
    for(int n=emp.size()-1;u1.name.size()<=m&&n>=0;n--){
        u1.name+=tolower(emp[n]);
    }
    int max = 0;
    FOR(i,x.size()){
        if(x[i].name == u1.name)
            max++;
    }
    //cout << u1.name << endl;
    if(u1.name.size()>1 && max == 0 && u1.name.size() > m){
        emp = u1.name.substr(0,u1.name.size()-1);
        //cout << emp << endl;
            FOR(i,x.size()){
                if(x[i].name == emp)
                    max++;
            }
        if( max > 0 ){
            u1.name = emp;
        }
    }
    if(u1.name.size()>2 && max==0 && u1.name.size()>m){
        emp = u1.name.substr(0,u1.name.size()-2);
        //cout << emp << endl;
            FOR(i,x.size()){
                if(x[i].name == emp)
                    max++;
            }
        if( max > 0 ){
            u1.name = emp;
        }
    }

    //cout << " :: " << u1.name << endl;
    u1.number = max;
    return u1;
};
int main(){
    /*
    2 6
    Jenny Ax
    Christos H Papadimitriou
    */
    int n,m;
    int co = 1;
    while(scanf("%d %d",&n,&m)){
        //cout << " :: " << n << m << endl;
        if(n==0 && m==0)
            break;

        bool s = true;
        string tmp ;
        getline(cin,tmp);
        //getline(cin,tmp);
        //n--;
        string num="";
        n++;
        while(n--){
            getline(cin,num);
            if(num!="")
                x.push_back(makeit(num,m));
            //cout << n << " NUM :: " << num << endl;
            if(n == 1)break;
        }
        cout << "Case " << co << endl;
        co++;
        for(int i=0;i<x.size();i++){
            if(x[i].number == 0){
                cout << x[i].name.substr(0,m) << endl;
            }else if(x[i].number<10){
                if(x[i].name.size()+1<=m)
                    cout << x[i].name << x[i].number << endl;
                else
                    cout << x[i].name.substr(0,m-1) << x[i].number << endl;
            }else {
                if(x[i].name.size()+2<=m)
                    cout << x[i].name << x[i].number << endl;
                else
                    cout << x[i].name.substr(0,m-2) << x[i].number << endl;
            }
        }
        x.clear();
    }
}
