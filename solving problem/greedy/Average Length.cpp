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
int dist[102][102];
void floyd() {
	int i, j, k;
	for (k = 1; k < n + 1; k++)
		for (i = 1; i < n + 1; i++)
			for (j = 1; j < n + 1; j++)
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
}
int main() {
	scanf("%d%d", &n, &m);
	MMS(dist, 0);
	FO(i , 1 , n+1)
		FO(j , 1 , n+1)
			dist[i][j] = 100000000;
	FO(i , 0 , m) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		dist[x][y] = z;
	}
	floyd();
	double tot = 0;
	int count = 0;
	FO(i , 1 , n+1) {
		FO(j, 1, n+1) {
			if (dist[i][j] != 100000000 && i != j) {
//				cout << i << " " << j << " " << dist[i][j] << endl;
				tot += dist[i][j];
				count++;
			}
		}
	}
//	cout << tot << " " << count << endl;
	printf("%0.6f\n", double(tot) / double(count));
	return 0;
}
