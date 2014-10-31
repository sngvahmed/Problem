#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int y = 0;
	int x[4] = { 25, 10, 5, 1 };
	while (n--) {
		y++;
		int num;
		int e = num;
		int d[4] = { 0, 0, 0, 0 };
		scanf("%d", &num);
		while (num != 0) {
			if (num >= x[0]) {
				num = num - x[0];
				d[0]++;
			} else if (num >= x[1]) {
				num = num - x[1];
				d[1]++;
			} else if (num >= x[2]) {
				num = num - x[2];
				d[2]++;
			} else if (num >= x[3]) {
				num = num - x[3];
				d[3]++;
			}
		}
		cout << y << " " << d[0] << " QUARTER(S), " << d[1] << " DIME(S), "
				<< d[2] << " NICKEL(S), " << d[3] << " PENNY(S)" << endl;
	}

	return 0;
}
