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

void generatePop() {
	int lw = 0, up = upper - lower;
	up *= pow(10.0, precision * 1.0);

	for (int i = 0; i < popCount; i++) {
		population.pb(rand() % (up + 1));
	}

	commulative.pb(0);
	for (int i = 0; i < popCount; i++) {
		commulative.pb(commulative[i - 1] + fitness(population[i]));
	}
}

int main() {
	srand(time(0));

	freopen("test.in", "rt", stdin);
	SF(lower), SF(upper), SF(precision), SF(popCount);
	generatePop();
	pair<int, int> parentIndex = getParent();
	return 0;
}
