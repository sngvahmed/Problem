#include <iostream>
#include <stdio.h>
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
	int max = arr[n-1];
	int min = arr[0];
	int gcd=0;
	for(int i=0;i<n-1;i++)
		if((arr[i]-arr[i+1])>gcd)
		gcd = (arr[i]-arr[i+1]);
		cout<<"Max "<<max<<", Min "<<min<<", Largest gap "<<gcd<<endl;

}
//Class 1
//Max 78, Min 23, Largest gap 46
int main() {
	int x;
	cin>>x;
	int count = 0;
	while (x--) {
		count ++;
		int w;
		cin>>w;
		int num[w];
		for (int i = 0; i < w; i++)
			cin >> num[i];
		cout<<"Class "<<count<<endl;
		selection(num, w);

	}
}
