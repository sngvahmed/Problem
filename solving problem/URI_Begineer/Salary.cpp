#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
#include <memory.h>
#include <climits>
#include <math.h>

using namespace std;

int main() {
	int A, B;
	float C;
	cin >> A >> B >> C;
	cout << "NUMBER = " << A << endl;
	cout << "SALARY = U$ " << setprecision(2) << fixed << double(B) * C << endl;
	return 0;
}
