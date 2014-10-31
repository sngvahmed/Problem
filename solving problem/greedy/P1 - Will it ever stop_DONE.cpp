/*When Bob was in library in University of Warsaw he saw on one of facades caption :"Will it ever stop?" and below some mysterious code:

 while n > 1
 if n mod 2 = 0 then
 n:=n/2
 else
 n:=3*n+3

 Help him finding it out !
 Input

 In first line one number n<=10^14.

 Output

 Print "TAK" if program will stop, otherwise print "NIE"

 Example

 Input:
 4

 Output:
 TAK
 *
 */
#include <iostream>
#include <vector>
#include <set>
#include <sstream>
typedef long long ll;
#define fr(n) for(int i=0;i<int(n);i++)
using namespace std;
int main() {
	long long x;
	cin >> x;
	int count = 0;
	while (x > 1) {
		if (x % 2 == 0)
			x = x / 2;
		else
			x = 3 * x + 3;
		if (x % 3 == 0) {
			cout << "NIE";
			return 0;
		}
		count++;
	}
	cout << "TAK";
	return 0;
}
