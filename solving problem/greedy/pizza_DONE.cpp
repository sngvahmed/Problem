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
using namespace std;
int main() {
	unsigned long long x;
	cin >> x;
	//	vector<int> count;
	/*if (d == "1/2") {
	 bool check = true;
	 for (int i = 0; i < count.size(); i++) {
	 if (count[i] >= 2) {
	 check = false;
	 count[i] = count[i] - 2;
	 break;
	 }
	 }
	 if (check == true)
	 count.push_back(2);
	 }*/
	vector<string> d;
	if (x == 0) {
		cout << "1";
		return 0;
	}
	int sum = 0;
	int count[3] = { 0, 0, 0 };
	for (int i = 0; i < x; i++) {
		d .push_back("");
		cin >> d[i];
		if (d[i] == "1/2")
			count[1]++;
		else if (d[i] == "1/4")
			count[0]++;
		else
			count[2]++;
	}
	//	cout << count[0] << count[1] << count[2] << endl;
	int dd = count[2];
	if (count[1] % 2 == 0)
		sum += (count[1] / 2);
	else {
		sum += ceil(double(count[1]) / double(2));
		dd += 2;
	}
	//	cout<<dd;
	sum += count[2];
	for (int i = 0; i < dd; i++) {
		count[0]--;
		if (dd == 0)
			break;
	}
//	cout << count[0] << endl;
	if (count[0] > 0) {
		//		cout<<"here"<<endl;
		sum += ceil(double(count[0]) / double(4));
	}
	cout << sum + 1;
//	system("pause");
	return 0;
}

