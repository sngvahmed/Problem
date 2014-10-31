#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int x, b;
	//scanf("%d %d", &x, &b) != -1
	while ((cin>>x>>b) && x!=-1) {
		int arr[x];
		for (int i = 0; i < x; i++)
			cin >> arr[i];
		int url = 0, urp = 5000000, c, temp;

		while(urp>url+1){
			temp = 0;
			c = (url + urp) / 2;
			//cout<<"c  "<<c<<endl;
			for (int i = 0; i < x; i++) temp += ceil((float)arr[i] / c);
			//cout<<"temp::   "<<temp<<endl;
			if (temp > b) url = c;
			else urp = c;
		}

		cout << urp <<endl;
	}

	return 0;
}
