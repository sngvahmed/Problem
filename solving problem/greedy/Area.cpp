#include "bits/stdc++.h"
#include <string>
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
int n, x, y;
class point {
public:
	int x, y;
	point(int x, int y) {
		this->x = x, this->y = y;
	}
};
vector<point> points;
long double polyarea() {
	int j;
	long double area = points[n - 1].x * points[0].y - points[n - 1].y * points[0].x;
	for (j = 1; j < n; j++)
		area += points[j - 1].x * points[j].y - points[j - 1].y * points[j].x;
	area /= 2.0;
	return area >= 0.0 ? area : -area;
}
int main() {
	scanf("%d", &n);
	FO(i , 0 ,n) {
		scanf("%d%d", &x, &y);
		points.push_back(point(x, y));
	}
	printf("%0.600LF", polyarea());
	return 0;
}
