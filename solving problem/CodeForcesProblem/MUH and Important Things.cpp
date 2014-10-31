// @Oct 13, 2014 MUH and Important Things.cpp
// 2014  sngv
#include "bits/stdc++.h"
#include <functional>
#include <ext/numeric> // for power long long 
using namespace std;

#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MMS(x, v) memset(x, v, sizeof(x))
#define SF(x) scanf("%d" , &x)

string toString(int num) {
  stringstream ss;
  string ret;
  ss << num, ss >> ret;
  return ret;
}

int main() {
  /*
   #ifndef ONLINE_JUDGE
   freopen("test.in", "rt", stdin);
   #endif
   */
  int x;
  SF(x);
  int tmp;
  vector<pair<int, int> > var;
  for (int i = 0; i < x; i++)
    SF(tmp), var.pb(mp(tmp, i + 1));
  sort(all(var));
  string arr[] = { "", "", "" };
  x = 0;
  for (int i = 0; i < SZ(var) ; i++) {
    if ((i < (SZ(var) - 2)) && x == 0 && (var[i].F == var[i + 1].F)
        && (var[i].F == var[i + 2].F)) {
      arr[0] += " " + toString(var[i].S), arr[0] += " "
          + toString(var[i + 1].S), arr[0] += " " + toString(var[i + 2].S);

      arr[1] += " " + toString(var[i + 1].S), arr[1] += " "
          + toString(var[i].S), arr[1] += " " + toString(var[i + 2].S);

      arr[2] += " " + toString(var[i + 2].S), arr[2] += " "
          + toString(var[i + 1].S), arr[2] += " " + toString(var[i].S);
      i++, i++;
      x = 2;
    } else if (i < SZ(var) - 1 && x == 0 && var[i].F == var[i + 1].F) {
      x = 1;
      arr[0] += " " + toString(var[i].S), arr[0] += " " + toString(var[i + 1].S);
      arr[1] += " " + toString(var[i + 1].S), arr[1] += " " + toString(var[i].S);
      arr[2] += " " + toString(var[i + 1].S), arr[2] += " " + toString(var[i].S);
      i++;
    } else if (i < SZ(var) - 1 && x == 1 && var[i].F == var[i + 1].F) {
      x = 2;
      arr[1] += " " + toString(var[i].S), arr[1] += " " + toString(var[i + 1].S);
      arr[0] += " " + toString(var[i + 1].S), arr[0] += " " + toString(var[i].S);
      arr[2] += " " + toString(var[i + 1].S), arr[2] += " " + toString(var[i].S);
      i++;
    } else {
      arr[0] += " " + toString(var[i].S);
      arr[1] += " " + toString(var[i].S);
      arr[2] += " " + toString(var[i].S);
    }
  }
  if (x != 2)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    cout << arr[0].substr(1, SZ(arr[0])) << endl;
    cout << arr[1].substr(1, SZ(arr[0])) << endl;
    cout << arr[2].substr(1, SZ(arr[0])) << endl;
  }

  return 0;
}
