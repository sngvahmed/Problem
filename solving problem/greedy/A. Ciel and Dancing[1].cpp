//http://codeforces.com/contest/322/problem/A
#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORE(n,a,b) for(int n=a;n<b;n++)
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	bool boy[n] ;
	bool girl[m];
	int resul1[10000];
	int resul2[10000];
	int size = 0;
	memset(boy,0,n);
	memset(girl,0,m);
	for (int i = 0; i < n; i++) {
		for (int y = 0; y < m; y++) {
			if (boy[i] == 0 || girl[y] == 0) {
				resul1[size] = i,resul2[size]=y;
				size++;
				boy[i] = girl[y] = 1;
			}
		}
	}
	cout << size << endl;
	for(int i=0;i<size;i++)

	    cout << resul1[i]+1 << " " << resul2[i]+1 << endl;
	return 0;
}
