#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
double At_least[4] = { 100000, 117250, 178650, 319100 };
double less_than[4] = { 117250, 178650, 319100, 1000000000 };
double multiplier[4] = { 0.25, 0.28, 0.33, 0.35 };
double subtraction[4] = { 6525, 10042.50, 18975, 25357 };
class TaxTable {
public:
	/*  At_least   Less_than    Multiplier       Subtraction
	 100,000     117,250        25%             6,525.00

	 117,250     178,650        28%            10,042.50

	 178,650     319,100        33%            18,975.00

	 319,100        -           35%            25,357.00

	 *
	 */
	int income(int taxAmount) {
		for (int i = 0; i < 4; i++) {
			cout << taxAmount << "    " << subtraction[i] << "   "
					<< multiplier[i] << endl;
			double x = (taxAmount + subtraction[i]);
			cout << x << endl;
			x = x / multiplier[i];
			cout << x << endl;
			if (At_least[i] <= x && less_than[i] >= x)
				return x;
		}

		return -1;
	}

};
