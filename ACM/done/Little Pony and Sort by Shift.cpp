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
#define SF(x) scanf("%d" , &x)

int main() {
	int n;
	SF(n);
	deque<int> arr(n);
	int counter = 0;
	for (int i = 0; i < SZ(arr) ; i++) {
		SF(arr[i]);
	}
	bool check = 1;
	for (int i = 0; i < SZ(arr) - 1; i++)
		if (arr[i] > arr[i + 1])
			check = 0;
	if (check) {
		cout << 0 << endl;
		return 0;
	}
	if (SZ(arr) == 2) {
		if (arr[0] <= arr[1]) {
			cout << 0 << endl;
		} else
			cout << 1 << endl;
		return 0;
	}
	int sz = 0;
	while (sz < SZ(arr) - 1) {
		int c = 0;
		while (sz < SZ(arr) - 1 && arr[sz] <= arr[sz + 1]) {
			sz++, c++;
		}
		if (c && sz != SZ(arr) - 2)
			counter++, sz++;
		else
			counter++;
		c = 0;
		while (sz < SZ(arr) - 1 && arr[sz] >= arr[sz + 1]) {
			sz++, c++;
		}
		if (c && sz != SZ(arr) - 2)
			counter++, sz++;
		else
			counter++;
	}
	sz = 0;
	int count = 0;
	while (sz < SZ(arr) - 1) {
		int c = 0;
		while (sz < SZ(arr) - 1 && arr[sz] >= arr[sz + 1]) {
			sz++, c++;
		}
		if (c && sz != SZ(arr) - 2)
			count++, sz++;
		else
			count++;
		c = 0;
		while (sz < SZ(arr) - 1 && arr[sz] <= arr[sz + 1]) {
			sz++, c++;
		}
		if (c && sz != SZ(arr) - 2)
			count++, sz++;
		else
			count++;
	}
	counter = min(count, counter);
	if (counter != 2) {
		cout << -1 << endl;
		return 0;
	}

	int i = 0, mx = 0, mn = 0;
	while (arr[i] < arr[i + 1])
		i++;
	mx = i;
	int mxx = SZ(arr) - 1, mnn = i + 1;
	if (arr[mn] < arr[mxx]) {
		cout << -1 << endl;
		return 0;
	}
	cout << mxx - mnn + 1 << endl;
	return 0;
}
