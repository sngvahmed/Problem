#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define fore(i,a) for(int i=0;i<a;i++)
using namespace std;
int main() {
	long long n, k1, k2, count = 1;
	while (true) {
		cin >> n >> k1 >> k2;
		if (n == 0 && k1 == 0 && k2 == 0)
			return 0;
		int *dy = new int[n];
		fore(i,n)
			cin >> dy[i];
		cout << "case " << count << endl;
		vector<long long> x;
		vector<long long> y;
		fore(i,k1)
			x.push_back(dy[i]);
		for (int q = n - 1; q >= n - k2; q--)
			y.push_back(dy[q]);
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		for (int i = 0; i < x.size(); i++)
			for (int q = i + 1; q < x.size(); q++)
				if (x[i] == x[q]) {
					x.erase(x.begin() + i);
					i--;
					q = i + 1;
				}
		for (int i = 0; i < y.size(); i++)
			for (int q = i + 1; q < y.size(); q++)
				if (y[i] == y[q]) {
					y.erase(y.begin() + i);
					i--;
					q = i + 1;
				}
		for (int i = 0; i < x.size(); i++)
			cout << x[i] << " ";
		cout << endl;
		for (int i = y.size()-1; i >=0; i--)
			cout << y[i] << " ";
		cout << endl;

		count++;
	}
}

