#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int k;
	scanf("%d", &k);
	int s = 0;
	while (k--) {
		s++;
		int num;
		scanf("%d", &num);
		long long sum = 0;
		long long counter = 1;
		for (int i = 1; i <= num; i++) {
			counter =counter + i + 1;
			sum = sum + (counter * i);
		}
		cout <<s<<" "<<num<<" "<<sum << endl;
	}

	return 0;
}
