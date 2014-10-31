//http://codeforces.com/problemset/problem/118/B
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
#define fore(i,a) for(int i=0;i<a.size();i++)
#define FOR(q,e) for(int q=0;q<e;q++)
int arr[100000];
int main() {
	int x;
	cin >> x;
	x = x * 2;
	int count = 0;
	for (int i = x; i >= 0; i = i - 2) {
		FOR(q,i)
			cout << " ";
		FOR(q,count)
			cout << q << " ";
		cout << count;
		for (int q = count - 1; q >= 0; q--)
			cout << " " << q;
		count++;
		cout << endl;
	}
	count--;
	for (int i = 2; i <= x; i = i + 2) {
		count--;
		//cout<<count<<endl;
		FOR(q,i)
			cout << " ";
		FOR(q,count)
			cout << q << " ";
		cout << count;
		for (int q = count - 1; q >= 0; q--)
			cout << " " << q;
		cout << endl;
	}
}
