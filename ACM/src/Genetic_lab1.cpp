#include "bits/stdc++.h"
#include <functional>
#include <ext/numeric> 
using namespace std;

#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MMS(x, v) memset(x, v, sizeof(x))
#define SF(x) scanf("%d" , &x)

int lower, upper;
int precision, popCount;
vector<int> population;
vector<int> commulative;

// return fitness (return equation)
int fitness(int x) {
	return x * x;
}
// ********************************

// **************************** get Random Parent ********************
int recheck(int comm) {
	int indx = upper_bound(all(commulative), comm) - commulative.begin();

	if (indx != 0)
		if (commulative[indx - 1] == comm)
			indx--;
	return indx;
}

pair<int, int> getParent() {
	int rem = commulative[SZ(commulative) - 1] + 1;
	int comm1 = rand() % rem, comm2 = rand() % rem;
	return mp(recheck(comm1), recheck(comm2));
}
// ********************************************************************

// ************** generate random population **************************
void generatePop() {
	int up = upper - lower;
	up *= pow(10.0, precision * 1.0);

	for (int i = 0; i < popCount; i++) {
		population.pb(rand() % (up + 1));
	}

	commulative.pb(0);
	for (int i = 0; i < popCount; i++) {
		commulative.pb(commulative[i - 1] + fitness(population[i]));
	}
}
// *******************************************************************
long long toDecimal(string s, int base) {
	long long v, i, result = 0;
	for (i = 0; i < (int) s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			v = s[i] - '0';
		else
			v = s[i] - 'A' + 10;
		result = result * base + v;
	}
	return result;
}
string toBase(long long num, int base) {
	if (num == 0)
		return "0";
	string str;
	while (num != 0) {
		int nlet = num % base;
		num /= base;
		if (nlet < 0) //for negative base
			num++, nlet += (-1 * base);
		if (nlet < 10)
			str += (nlet + '0');
		else
			str += (nlet - 10 + 'A');

	}
	reverse(str.begin(), str.end());
	return str;
}
int mutuation(int num) {
	string str = toBase(num, 2);
	int indx = rand() % SZ(str);
	str[indx] = (str[indx] == '0') ? '1' : '0';
	return toDecimal(str, 2);
}
pair<int, int> crossOver(int i1, int i2) {
	string num1 = toBase(i1, 2), num2 = toBase(i2, 2);
	string sub1 = num1.substr(0, SZ(num1) / 2)
			+ num2.substr((SZ(num2) / 2) + 1, SZ(num1));

	string sub2 = num2.substr(0, SZ(num1) / 2)
			+ num1.substr((SZ(num2) / 2) + 1, SZ(num1));

	return mp(toDecimal(sub1, 2), toDecimal(sub2, 2));
}
// *********************************************
int main() {
	srand(time(0));

	freopen("test.in", "rt", stdin);
	SF(lower), SF(upper), SF(precision), SF(popCount);
	generatePop();
	pair<int, int> parentIndex = getParent();
	return 0;
}
