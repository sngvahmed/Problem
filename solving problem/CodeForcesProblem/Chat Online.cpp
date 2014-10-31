// @Oct 12, 2014 Chat Online.cpp
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

int main() {
//#ifndef ONLINE_JUDGE
//    freopen("test.in", "rt", stdin);
//#endif
  int p, q, l, r;
  scanf("%d%d%d%d", &p, &q, &l, &r);
  vector<pair<int, int> > vp, vq;
  for (int i = 0; i < p; i++) {
    int tmpf, tmps;
    scanf("%d%d", &tmpf, &tmps), vp.pb(mp(tmpf, tmps));
  }
  for (int i = 0; i < q; i++) {
    int tmpf, tmps;
    scanf("%d%d", &tmpf, &tmps), vq.pb(mp(tmpf, tmps));
  }
  sort(all(vp)), sort(all(vq));

  int tot = 0;
  int arr[1001];
  MMS(arr, 0);
  for (int i = 0; i < SZ(vp) ; i++)
    for (int j = 0; j < SZ(vq) ; j++)
      for (int k = l; k <= r; k++) {
        int vfnew = vq[j].F + k, vsnew = vq[j].S + k;
        if (!(vfnew > vp[i].S || vsnew < vp[i].F))
          arr[k] = 1;
      }

  for (int i = l; i <= r; i++)
    if (arr[i])
      tot++;

  cout << tot << endl;
  return 0;
}
