#include "bits/stdc++.h"
#include <functional>
#include <ext/numeric>
using namespace std;

#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MMS(x, v) memset(x, v, sizeof(x))
#define SF(x) scanf("%d" , %x)
int arr[100][100];
int vis[100][100];

struct point {
    int x, y, val;
    point(int xx, int yy, int vall) {
        x = xx, y = yy, val = vall;
    }
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("test.in", "rt", stdin);
#endif
    MMS(arr, 1);
    int n, m;
    cin >> n >> m;
    vector<point> var;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x, y, val;
            cin >> val;
            x = i, y = j;
            var.pb(point(x, y, val));
        }
    }
    for (int i = 0; i < SZ(var); i++) {
        if (var[i].val == 0) {
            for (int l = 0; l < m; l++) {
                arr[var[i].x][l] = 0;
            }
            for (int l = 0; l < n; l++) {
                arr[l][var[i].y] = 0;
            }
        }
    }
    for (int i = 0; i < SZ(var); i++) {
        if (var[i].val == 1) {
            bool check = false;
            for (int l = 0; l < m; l++) {
                if (arr[var[i].x][l] != 0)
                    check = 1;
            }
            for (int l = 0; l < n; l++) {
                if (arr[l][var[i].y] != 0)
                    check = 1;
            }
            if(!check){
                cout << "NO" << endl;
                return 0;
            }
        }

    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == m - 1) {
                if (arr[i][j])
                    cout << 1;
                else
                    cout << 0;
            } else {
                if (arr[i][j])
                    cout << 1 << " ";
                else
                    cout << 0 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
