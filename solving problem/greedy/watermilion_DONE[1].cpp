#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int x;
	cin>>x;
	if (x>= 4) {
            int e = x/2;
		double q = double(x)/2;
		if(q>e)
		e++;
		if (q >= 2 && e % 2 == 0)
			cout << "YES";
		else
			cout << "NO";
	} else
		cout << "NO";
//	system("pause");
    return 0;
}
