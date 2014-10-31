#include "bits/stdc++.h"
using namespace std;
#define FO(i, a, x) for(int i = a; i < (int)x; i++)
#define F first
#define S second
int dip[] = { 0, 1, 0, -1 };
int djp[] = { 1, 0, -1, 0 };
int diq[] = { 0, 1, 0, -1 };
int djq[] = { 1, 0, -1, 0 };
int n, m, p;
vector<int> S, E;
map<vector<int>, vector<vector<int> > > mp;
map<vector<int>, bool> vis;
void DFS(vector<int> x) {
	if (x == E) {
		p = 1;
		return;
	}
	if (p != 1) {
		FO(i,0,mp[x].size()) {
			if (vis[mp[x][i]] == 0 && p != 1) {
				vis[mp[x][i]] = 1;
				DFS(mp[x][i]);
			}
		}
	}
}
int main() {
	int to = 1;
	while (cin >> n && n) {
		S.clear(), E.clear(), vis.clear(), mp.clear();
		S.resize(n), E.resize(n);
		FO(i , 0 , n)
			cin >> S[i];
		FO(i , 0 , n)
			cin >> E[i];
		while (true) {
			vector<int> vars(n), vard(n);
			cin >> vars[0];
			if (vars[0] == -1)
				break;
			FO (i , 1 , n)
				cin >> vars[i];
			FO (i , 0 , n)
				cin >> vard[i];
			mp[vars].push_back(vard);
			mp[vard].push_back(vars);
		}
		p = 0;
		DFS(S);
		if (p == 1) {
			printf("Maze #%d can be travelled\n", to++);
		} else
			printf("Maze #%d cannot be travelled\n", to++);
	}
	return 0;
}
