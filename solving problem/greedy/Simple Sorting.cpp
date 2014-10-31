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

void merge(int *a, int *b, int low, int pivot, int high) {
	int h, i, j, k;
	h = low, i = low, j = pivot + 1;

	while ((h <= pivot) && (j <= high)) {
		if (a[h] <= a[j]) {
			b[i] = a[h], h++;
		} else {
			b[i] = a[j], j++;
		}
		i++;
	}
	if (h > pivot) {
		for (k = j; k <= high; k++) {
			b[i] = a[k], i++;
		}
	} else {
		for (k = h; k <= pivot; k++) {
			b[i] = a[k], i++;
		}
	}
	for (k = low; k <= high; k++)
		a[k] = b[k];
}

void MergeSort(int *a, int*b, int low, int high) {
	if (low < high) {
		int pivot = (low + high) / 2;
		MergeSort(a, b, low, pivot);
		MergeSort(a, b, pivot + 1, high);
		merge(a, b, low, pivot, high);
	}
}

int main() {

	cin >> n;
	int arr[n];
	FO(i , 0 , n)
		cin >> arr[i];
	if (n == 1) {
		cout << arr[0] << endl;
		return 0;
	}
	int num;
	num = sizeof(arr) / sizeof(int);
	int ret[num];
	MergeSort(arr, ret, 0, num - 1);
	set<int> se;
	FO(i , 0 , n) {
		se.insert(arr[i]);
	}
	if (n % 2 == 0) {
		for (set<int>::iterator it = --se.end(); it != se.begin(); it--) {
			cout << *it << endl;
		}
		cout << *se.begin() << endl;
	} else {
		for (set<int>::iterator it = se.begin(); it != se.end(); it++) {
			cout << *it << endl;
		}
	}
	return 0;
}
