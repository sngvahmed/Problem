// May 22, 2014 , prim.cpp 
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
map<int, vi> var;
int n, m;
map<int, vi> nod;
bool vis[100];
int cost[100][100];
map<int, vector<pair<int, int> > > wh;

bool comp(const Hamada &a, const Hamada &b) {
	return (a.S.S < b.S.S) ? 1 : 0;
}
int minumSpamTree(int f) {
	vector<Hamada> que;
	FO(i , 0 , SZ(wh[f])) {
		que.push_back(Hamada(mp(f, mp(wh[f][i].F, wh[f][i].S))));
		vis[f] = 1, cost[f][wh[f][i].F] = cost[wh[f][i].F][f] = 1;
	}
	int nod = n - 1, tot = 0;
	cout << que.size() << endl;
	while (que.size()) {
		sort(all(que), comp);
		Hamada tmp = que[0];
		que.erase(que.begin());
		cout << nod << " :: " << que.size() << endl;
		if (nod == 0)
			return tot;
		if (vis[tmp.F] == 1 && vis[tmp.S.F] == 1)
			continue;
		tot += tmp.S.S;
		cout << tot << " " << tmp.F << " " << tmp.S.F << endl;
		f = tmp.F;
		FO(i , 0 , SZ(wh[f]))
			if (cost[f][wh[f][i].F] == 0)
				que.push_back(Hamada(mp(f, mp(wh[f][i].F, wh[f][i].S)))), cost[f][wh[f][i].F] =
						cost[wh[f][i].F][f] = 1;
		f = tmp.S.F;
		FO(i , 0 , SZ(wh[f]))
			if (cost[f][wh[f][i].F] == 0)
				que.push_back(Hamada(mp(f, mp(wh[f][i].F, wh[f][i].S)))), cost[f][wh[f][i].F] =
						cost[wh[f][i].F][f] = 1;
	}
	return tot;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
#endif
	scanf("%d%d", &n, &m);
	FO(i , 0 , m) {
		int t1, t2, w;
		scanf("%d%d%d", &t1, &t2, &w);
		wh[t1 - 1].pb(mp(t2 - 1, w)), wh[t2 - 1].pb(mp(t1 - 1, w));
	}
	cout << minumSpamTree(0) << endl;
	return 0;
}
// CPY @SNGV
