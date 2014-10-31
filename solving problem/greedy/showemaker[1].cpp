//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=967
// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<iostream>
using namespace std;
int main() {
	double tot[10000];
	int time[10000];
	int indx[10000];
	/*
	 4
	 3 4
	 1 1000
	 2 2
	 5 5
	 */
	int co;
	cin >> co;
	int nc = co;
	int e = 0;
	while (co--) {
		int times;
		cin >> times;
		int i = 0;
		int s = times;
		while (s--) {
			int temp;
			cin >> time[i] >> temp;
			tot[i] = double(temp) / double(time[i]);
			indx[i] = i;
			i++;
		}
		for (i = 0; i < times; i++) {
			int w = i;
			for (int k = i + 1; k < times; k++) {
				if (tot[w] < tot[k])
					w = k;
				else if (tot[w] == tot[k]) {
					if (indx[w] > indx[k])
						w = k;
				}
			}
			swap(tot[w], tot[i]);
			swap(time[w], time[i]);
			swap(indx[w],indx[i]);
		}
		//for (i = 0; i < times; i++)cout << tot[i] << " ";
		
		for (i = 0; i < times; i++)
			if (i == times - 1)
				cout << indx[i]+1;
			else
				cout << indx[i]+1 << " ";
		cout << endl;
	  if (e < nc-1) {
		cout << endl;
	   }
	e++;
	}
	return 0;
}
