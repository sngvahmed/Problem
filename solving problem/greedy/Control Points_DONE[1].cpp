#include <iostream>
#include <fstream>
#include <memory.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int main() {

#ifndef ONLINE_JUDGE
    freopen("test.txt","rt",stdin);
    //freopen("out.txt","wt",stdout);
#endif
	int num;
	int count = 0;
	double q ;
	while(cin >> num)
	{
	double x[num];
	for (int i = 0; i < num; i++)
		cin >> x[i];
	 if (x == 0)
	 count = 0;
	q== x[0];
	for (int i = 1; i < num; i++) {
		if ((x[i] - q) > (double) 1 - (1e-9)) {
			q = x[i];
			count++;
		}
	}
	cout << count<<endl;
	}

	/*
	 int x, ans;
	 double stillCover;
	 while (cin >> x) {
	 ans = 1;
	 if (x == 0)
	 ans = 0;
	 double arr[x];
	 for (int i = 0; i < x; i++)
	 cin >> arr[i];
	 stillCover = arr[0];
	 for (int i = 1; i < x; i++)
	 if ((arr[i] - stillCover) > (double) 1 - (1e-9)) {
	 stillCover = arr[i];
	 ans++;
	 }
	 cout << ans << endl;
	 }
	 */
	return 0;
}
