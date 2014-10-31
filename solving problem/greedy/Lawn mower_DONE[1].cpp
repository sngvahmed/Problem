#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void selection(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int w = i;
		for (int k = i + 1; k < n; k++) {
			if (arr[w] < arr[k])
				w = k;
		}
		swap(arr[w], arr[i]);
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}
}

int main() {
	int x, y;
	double n;
	while (cin >> x >> y >> n) {
		if (x == 0 && y == 0 && n == 0.0)
			return 0;
		n = n / 2.0;
		double num1[x];
		double num2[y];
		for (int i = 0; i < x; i++)
			cin >> num1[i];
		for (int i = 0; i < y; i++)
			cin >> num2[i];
		for (int i = 0; i < x; i++) {
			int w = i;
			for (int k = i + 1; k < x; k++) {
				if (num1[w] < num1[k])
					w = k;
			}
			swap(num1[w], num1[i]);
		}
		for (int i = 0; i < y; i++) {
			int w = i;
			for (int k = i + 1; k < y; k++) {
				if (num2[w] < num2[k])
					w = k;
			}
			swap(num2[w], num2[i]);
		}
		bool check = true;
		/*for(int i=0;i<x;i++)cout<<num1[i];
		 cout<<endl;
		 for(int i=0;i<y;i++)cout<<num2[i];*/
		if (num1[0] - n > 0 || num2[0] - n > 0 || num1[x - 1] + n < 75
				|| num2[y - 1] + n < 100)
			check = false;
		for (int i = 0; i < x - 1; i++) {
			double ser = (double) num1[i + 1] - num1[i];
			if (ser < 0)
				ser = ser * -1;
			if (ser != n && num1[i + 1] >= n && num1[i] >= n) {
				check = false; /*cout<<ser<<"    "<<n<<"    "<<num1[i]<<"    "<<num1[i+1]<<endl;*/
			}
		}
		for (int i = 0; i < y - 1; i++) {
			double ser = (double) num2[i + 1] - num2[i];
			if (ser < 0)
				ser = ser * -1;
			if (ser != n && num2[i] >= n && num2[i + 1] >= n) {
				check = false; /*cout<<"here"<<ser<<"    "<<n<<"    "<<num2[i]<<"    "<<num2[i+1]<<endl;*/
			}
		}
		if (check != false)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
