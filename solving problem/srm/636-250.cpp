// @Oct 14, 2014 636-250.cpp
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

class GameOfStones {
 public:
  int count(vector<int> stones) {
    int mx = 1000000;
    int num = 0;
    int tot = 0;
    for (int i = 0; i < SZ(stones) ; i++) {
      tot += stones[i];
    }

    if (tot % SZ(stones) != 0) {
      return -1;
    }

    while (true && mx) {
      sort(all(stones));
      if (stones[0] == stones[SZ(stones) - 1])
        break;
      if (stones[SZ(stones) - 1] < 3) {
        return -1;
      }
      mx--, num++;
      stones[0] += 2;
      stones[SZ(stones) - 1] -= 2;
    }
    if (mx)
      return num;
    return -1;
  }
};
