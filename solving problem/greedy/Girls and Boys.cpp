#include <iostream>
#include <vector>
#include <set>
#include <sstream>
typedef long long ll;
#define fr(n) for(int i=0;i<int(n);i++)
using namespace std;
int main() {
	int g, t;
	cin >> g >> t;
	if (g < 0 || t < 0)
		cout << " ";
	else if (g == t)
		cout << g / t;
	else if (g == 0)
		cout << t;
	else if (t == 0)
		cout << g;
	else {
		int l = max(g, y) / min(g, y);
		while (l != 0) {
			if (t == 0) {
				cout << g - 1;
				return 0;
			} else if (g == 0) {
				cout << t;
				return 0;
			}
			g--;
			t--;
		}
	}

	return 0;
}
