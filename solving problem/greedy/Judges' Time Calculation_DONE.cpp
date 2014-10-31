#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int xh, xm, yh, ym;
		scanf("%d %d %d %d", &xh, &xm, &yh, &ym);
		xm = xm * -1;
		cout << "------+---------\n";
		cout << " time | elapsed\n";
		cout << "------+---------\n";
		if (xm != 0)
			if (xh > 9)
				cout << xh << ":XX " << "| " << "XX - " << abs(xm) << endl;
			else
				cout << " " << xh << ":XX " << "| " << "XX - " << abs(xm)
						<< endl;
		else if (xh > 9)
			cout << xh << ":XX " << "| " << "XX" << endl;
		else
			cout << " " << xh << ":XX " << "| " << "XX" << endl;
		int q = xm;
		q = abs((xm * -1) + ym);
		if (q >= 60)
			yh += 1;
		for (int s = 0; s < yh; s++) {
			xh++;
			xm += 60;
			if (xh > 12)
				xh = 1;
			if (xh > 9)
				cout << xh << ":XX " << "| " << "XX + " << xm << endl;
			else
				cout << " " << xh << ":XX " << "| " << "XX + " << xm << endl;
		}

	}
	return 0;
}
