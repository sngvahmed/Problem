//http://www.codeforces.com/problemset/problem/56/A
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
#define For(i,a,b) for(int i=a;i<i<b;i++)
#define Fors(i,a) for(int i=0;i<a.size();i++)
using namespace std;
int main() {
	bool c1 = false;
	bool c2 = false;
	bool c3 = false;
	bool c5 = false;
	string x;
	char d[100];
	scanf("%s", d);
	x = d;
	int count = 0;
	Fors(i,x) {
		//aaaaahhhheeeelllloooo
		//		cout<<x[i]<<endl;
		if (x[i] == 'H' || x[i] == 'h' || x[i] == 'e' || x[i] == 'E' || x[i]
				== 'L' || x[i] == 'l' || x[i] == 'O' || x[i] == 'o') {
			if (x[i] == 'H' || x[i] == 'h') {
				c1 = true;
			} else if (c1 == true && (x[i] == 'e' || x[i] == 'E')) {
				c2 = true;
			} else if (c2 == true && (x[i] == 'l' || x[i] == 'L')) {
				c3 = true;
				count++;
			} else if (c3 == true && (x[i] == 'o' || x[i] == 'O')) {
				c5 = true;
			}
		}
	}
	if (c1 == true && c2 == true && c3 == true && c5 == true && count >= 2)
		cout << "YES";
	else
		cout << "NO";
	//	system("pause");
	return 0;
}

