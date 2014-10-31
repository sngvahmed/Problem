#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <math.h>
typedef unsigned long long llg;
#define FOR(i,var) for(unsigned long long i=0;i<var;i++)
using namespace std;
/*int main() {
 unsigned long long x[2];
 /*2 3
 500 700
 700 500 500*/
/*while (true) {
 int i = 0;
 cin >> x[0] >> x[1];
 cout << x[0] << x[1] << endl;
 int *z1 = new int[x[0]];
 int *z2 = new int[x[1]];
 FOR(i,x[0])
 cin>>z1[i];
 FOR(i,x[1])
 cin>>z2[i];
 bool check;
 for (i = 0; i < x[1]; i++) {
 check = true;
 for (int q = 0; q < x[0]; q++) {
 if (z2[i] > z1[q]) {
 check = false;
 break;
 }
 }
 if (check == false)
 break;
 }
 if (check == true)
 cout << "N" << endl;
 else
 cout << "Y" << endl;

 }
 return 0;
 }*/

void sort(int a[]) {
	int i, j, t;
	for (i = 1; i < a[0]; i++) {
		for (j = i + 1; j <= a[0]; j++)
			if (a[i] > a[j]) {
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
	}
}
int main() {
	int a[16], d[16], i;
	while (true) {
		scanf("%d%d", &a[0], &d[0]);
		if (!a[0] && !d[0])
			break;
		for (i = 1; i <= a[0]; i++)
			scanf("%d", &a[i]);
		for (i = 1; i <= d[0]; i++)
			scanf("%d", &d[i]);
		sort(a);
		sort(d);
		if (a[1] < d[2])
			printf("Y\n");
		else
			printf("N\n");
	}
	return 0;
}
