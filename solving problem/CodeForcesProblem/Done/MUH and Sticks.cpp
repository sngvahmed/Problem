// @Oct 5, 2014 @2:12:18 PM @2014
#include "bits/stdc++.h"
#include <functional>

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
typedef pair<int, vi> pi;
typedef pair<int, int> vp;
typedef pair<int, pair<int, int> > Hamada;

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "rt", stdin);
#endif
          set<int> vec;
          map<int, int> var;
          int tmp;
          int t1, t2, t3;
          t1 = t2 = t3 = -1;
          FO(i,0,6)
          {
            cin >> tmp, var[tmp]++;
            if (t1 == -1 || t1 == tmp) {
              t1 = tmp;
            } else if (t2 == -1 || t2 == tmp) {
              t2 = tmp;
            } else if (t3 == -1 || t3 == tmp) {
              t3 = tmp;
            } else
            t1 = -2;
          }
//  cout << var[t1] << " " << var[t2] << " " << var[t3] << endl;
          vi vr;
          vr.pb(var[t1]), vr.pb(var[t3]), vr.pb(var[t2]);
          sort(all(vr));
          if (t1 == -2 || (vr[0] < 4 && vr[1] < 4 && vr[2] < 4)) {
            cout << "Alien" << endl;
          } else if ((vr[2] == 4 && vr[1] == 2) || vr[2] == 6)
          cout << "Elephant" << endl;
          else
          cout << "Bear" << endl;
          return 0;
        }
// CPY @SNGV
