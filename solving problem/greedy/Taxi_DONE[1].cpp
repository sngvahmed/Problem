//http://codeforces.com/problemset/problem/158/B
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
void selection(int n) {
	for (int i = 0; i < n; i++) {
		int w = i;
		for (int k = i + 1; k < n; k++) {
			if (arr[w] < arr[k])
				w = k;
		}
		swap(arr[w], arr[i]);
	}
}
int main() {
	int x;
	int count = 0;
	cin >> x;
	FOR(q,x)
		cin >> arr[q];
	//selection(x);
	int a = 0, b = 0, c = 0, d = 0;
	FOR(q,x)
		if (arr[q] == 1)
			a++;
		else if (arr[q] == 2)
			b++;
		else if (arr[q] == 3)
			c++;
		else if (arr[q] == 4)
			d++;
	//cout<<a<<b<<c<<d<<endl;
	count = d;
	if (c == a) {
		count += ceil((double) b / 2);
		count += c;
	} else if (c > a) {
		c = c - a;
		count += a;
		count += c;
		count += ceil((double) b / 2);
	} else if (c < a) {
		a = a - c;
		count += c;
		if (b % 2 == 0) {
			count += b / 2;
			b = 0;
			count += ceil((double) a / 4);
		} else {
			count += b / 2;
			b = 1;
			//cout<<"heress"<<endl;
			if (a >= 1) {
				//cout<<"here"<<endl;
				if (a == 1)
					a = a - 1;
				else
					a = a - 2;
				count += b;
				count += ceil((double) a / 4);
			} else {
				count += b;
				count += ceil((double) a / 4);
			}
		}
	}
	cout << count;
	return 0;
}
