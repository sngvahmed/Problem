// @Oct 14, 2014 srm 441-250.cpp
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

class DifferentStrings {
 public:

  int minimize(string A, string B) {
    int diff = 0;

    if (SZ(A) == SZ(B)) {
      for (int i = 0; i < SZ(B) ; i++) {
        if (A[i] != B[i])
          diff++;
      }
      return diff;
    }
    diff = SZ(B) - SZ(A);

    int diff1, diff2, diff3;
    diff1 = diff2 = diff3 = 1 << 30;
    if (B.find(A))
      return 0;

    for (int i = 0; i < SZ(B) - diff; i++) {
      diff2 = 0;
      for (int j = 0; j < SZ(A) ; j++) {
        if(A[j]!=B[j+i])diff2++;
      }
      diff1 = min (diff1 , diff2);
    }

    return diff1;
  }
};
