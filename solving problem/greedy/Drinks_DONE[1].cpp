//http://codeforces.com/problemset/problem/200/B
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fore(i,a) for(int i=0;i<a.size();i++)
#define FOR(q,e) for(int q=0;q<e;q++)
int main() {

	int x;
	cin >> x;
	int arr[x];
	long long sum = 0;
	FOR(q,x) {
		cin >> arr[q];
		sum += arr[q];
	}
	cout.precision(8);
	cout << fixed << sum;

	return 0;
}
