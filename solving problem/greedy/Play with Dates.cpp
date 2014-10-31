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
#include <math.h>
using namespace std;

#define FO(i, a, x) for(int i = a; i < (int)x; i++)
#define FOR(i, x) FO(i, 0, x)
#define RO(i, a, x) for(int i = a; i >= x; i--)
#define ROF(i, x) for(int i = x; i >= 0; i--)
#define FOUND(s, x) find(all(s), x) != s.end()
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pr pair<int, int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MMS(x, v) memset(x, v, sizeof(x))
#define SQ(x) (x) * (x)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<string> vs;
typedef vector<int> vi;

char *getName(int day){ //returns the name of the day
   switch(day){
      case 0 :return("Sunday");
      case 1 :return("Monday");
      case 2 :return("Tuesday");
      case 3 :return("Wednesday");
      case 4 :return("Thursday");
      case 5 :return("Friday");
      case 6 :return("Saturday");
      default:return("");
   }
}

int getDayNumber(int dd,int mm,int yy){ //retuns the day number
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    yy -= mm < 3;
    return (yy + yy/4 - yy/100 + yy/400 + t[mm-1] + dd) % 7;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("test.in", "rt", stdin);
    #endif
    int n ;
    scanf("%d", &n);
 	  while(n -- ){
      int dd, mm, yy;
      scanf("%d%d%d", &dd, &mm, &yy);
      printf(getName(getDayNumber(dd, mm, yy)));
      cout << endl;
    }
    return 0;
}
