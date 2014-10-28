// @Oct 12, 2014 Plate Game.cpp
// 2014  sngv
#include "bits/stdc++.h"
#include <functional>
#include <ext/numeric> // for power long long 
using namespace std;

#define FO(i, a, x) for(int i = a; i < (int)x; i++)
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MMS(x, v) memset(x, v, sizeof(x))

int main() {
  int n, m, y;
  cin >> n >> m >> y;
  if (!(2 * y > n || 2 * y > m))
    cout << "First" << endl;
  else
    cout << "Second" << endl;
  return 0;
}

