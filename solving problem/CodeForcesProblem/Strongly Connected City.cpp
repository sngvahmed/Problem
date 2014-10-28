// @Oct 11, 2014
// @CPY sngv ..... Strongly Connected City.cpp 
#include "bits/stdc++.h"
#include <functional>
#include <ext/numeric> // for power long long 

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
int n,m;
int vis[20][20];
bool vaild(int i, int j){
	return (i < 0 || i >= n || j < 0 || j >= m) ? 0 : 1;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif

	scanf("%d%d", &n, &m);
	string sn,sm;
	cin >> sn >> sm;
	map<char, int> dir;
	dir['>'] = 1, dir['v'] = 1, dir['^'] = -1, dir['<'] = -1;
	FO(i , 0 , n)
		FO(j,0,m)
		{
			queue<pair<int, int> > Q;
			Q.push(mp(i, j)), MMS(vis, 0);
			bool vs = 0;
			while (Q.size()) {
				pair<int, int> pr = Q.front();
				Q.pop();
				if (vis[i][j] == 1 && i == pr.F && j == pr.S) {
					vs = 1;
					break;
				}
				int NM = pr.S + dir[sn[pr.F]];
				if (vaild(pr.F, NM) && !vis[pr.F][NM])
					vis[pr.F][NM] = 1, Q.push(mp(pr.F, NM));

				NM = pr.F + dir[sm[pr.S]];
				if (vaild(NM, pr.S) && !vis[NM][pr.S])
					vis[NM][pr.S] = 1, Q.push(mp(NM, pr.S));
			}
			if (vs == 0) {
				cout << "NO" << endl;
				return 0;
			}
		}

	cout << "YES" << endl;
	return 0;
}
