#include<bits/stdc++.h>

using namespace std;

#define FO(i, a, x) for(int i = a; i < (int)x; i++)
#define RO(i, a, x) for(int i = a; i >= x; i--)
#define FORIT(it, x) for(typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define FOUND(s, x) find(all(s), x) != s.end()
#define NOTFOUND(s, x) find(all(s), x) == s.end()
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MMS(x, v) memset(x, v, sizeof(x))
#define SQ(x) (x) * (x)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<string> vs;
typedef vector<int> vi;

void ANYFILE() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
}

int main(){
    ANYFILE();
    int num , mx = -1;
    scanf("%d" , &num);
    int arr[num];
    FO(i,0,num){scanf("%d",&arr[i]); if(i>0)mx = max(mx , abs(arr[i]-arr[i-1]));}
    int ans = 1 << 30;
    FO(i,1,num - 1){
        ans = min(abs(arr[i+1]-arr[i-1]) , ans);
        if(ans <= mx){cout << mx << endl; return 0;}
    }
    cout << ans << endl;
}
