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

class IdentifyingWood {
public:
	string check(string s, string t) {
		int j = 0;
		for (int i = 0; i < SZ(s); i++) {
			if (s[i] == t[j]) {
				j++;
			}
		}
		if (j == SZ(t))
			return "Yep, it's wood.";
		else
			return "Nope.";
	}
};
