#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int main(void) {
	while (true) {
		int x[3];
		scanf("%d %d %d", &x[0], &x[1], &x[2]);
		if (x[1] == 0 && x[1] == 0 && x[2] == 0)
			return 0;
		bool check2 = false, check = false;
		int a, b, c, num;
		sort(x, x + 3);
		a = x[0], b = x[1], c = x[2];
		if (a == b && b == c)
			check2 = true;
		else if (a == b || b == c) {
			check = true;
			if (a == b)
				num = c;
			else
				num = a;
		}
		if (check2 && a == 13)
			puts("*");
		else if (check2)
			printf("%d %d %d\n", a + 1, a + 1, a + 1);
		else if (check) {
			if (b == 13 && num == 12)
				puts("1 1 1");
			else {
				while (true) {
					num = num + 1;
					if (num == 14) {
						num = 1;
						++b;
					}
					if (num != b)
						break;
				}
				x[0] = x[1] = b;
				x[2] = num;
				sort(x, x + 3);
				cout << x[0] << " " << x[1] << " " << x[2] << endl;
			}
		} else
			puts("1 1 2");
	}
	return 0;
}
