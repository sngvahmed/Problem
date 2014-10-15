//============================================================================
// Author      : Ahmed nasser
// Version     : 1
// Copyright   : 150
// Description : 495_DIV2_500_DONE
//============================================================================
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

#define FO(i, a, x) for(int i = a; i < (int)x; i++)
#define FOR(i, x) FO(i, 0, x)
#define RO(i, a, x) for(int i = a; i >= x; i--)
#define ROF(i, x) for(int i = x; i >= 0; i--)
#define FORIT(it, x) for(typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define FOUND(s, x) find(all(s), x) != s.end()
#define NOTFOUND(s, x) find(all(s), x) == s.end()
#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MMS(x, v) memset(x, v, sizeof(x))
#define SQ(x) (x) * (x)
#define REP(i,b) for(int i=0;i<b;++i)
#define REPD(i,b) for(int i=b-1;i>=0;--i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define FILL(a,b) memset(a,b,sizeof a)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<string> vs;
typedef vector<int> vi;
class KingSort {
public:
	map<string, int> m;
	map<int, string> s;
	void markz() {
		m["I"] = 1, s[1] = "I";
		m["II"] = 2, s[2] = "II";
		m["III"] = 3, s[3] = "III";
		m["IV"] = 4, s[4] = "IV";
		m["V"] = 5, s[5] = "V";
		m["VI"] = 6, s[6] = "VI";
		m["VII"] = 7, s[7] = "VII";
		m["VIII"] = 8, s[8] = "VIII";
		m["IX"] = 9, s[9] = "IX";
		m["X"] = 10, s[10] = "X";
		m["XI"] = 11, s[11] = "XI";
		m["XII"] = 12, s[12] = "XII";
		m["XIII"] = 13, s[13] = "XIII";
		m["XIV"] = 14, s[14] = "XIV";
		m["XV"] = 15, s[15] = "XV";
		m["XVI"] = 16, s[16] = "XVI";
		m["XVII"] = 17, s[17] = "XVII";
		m["XVIII"] = 18, s[18] = "XVIII";
		m["XIX"] = 19, s[19] = "XIX";
		m["XX"] = 20, s[20] = "XX";
		m["XXI"] = 21, s[21] = "XXI";
		m["XXII"] = 22, s[22] = "XXII";
		m["XXIII"] = 23, s[23] = "XXIII";
		m["XXIV"] = 24, s[24] = "XXIV";
		m["XXV"] = 25, s[25] = "XXV";
		m["XXVI"] = 26, s[26] = "XXVI";
		m["XXVII"] = 27, s[27] = "XXVII";
		m["XXVIII"] = 28, s[28] = "XXVIII";
		m["XXIX"] = 29, s[29] = "XXIX";
		m["XXX"] = 30, s[30] = "XXX";
		m["XXXI"] = 31, s[31] = "XXXI";
		m["XXXII"] = 32, s[32] = "XXXII";
		m["XXXIII"] = 33, s[33] = "XXXIII";
		m["XXXIV"] = 34, s[34] = "XXXIV";
		m["XXXV"] = 35, s[35] = "XXXV";
		m["XXXVI"] = 36, s[36] = "XXXVI";
		m["XXXVII"] = 37, s[37] = "XXXVII";
		m["XXXVIII"] = 38, s[38] = "XXXVIII";
		m["XXXIX"] = 39, s[39] = "XXXIX";
		m["XL"] = 40, s[40] = "XL";
		m["XLI"] = 41, s[41] = "XLI";
		m["XLII"] = 42, s[42] = "XLII";
		m["XLIII"] = 43, s[43] = "XLIII";
		m["XLIV"] = 44, s[44] = "XLIV";
		m["XLV"] = 45, s[45] = "XLV";
		m["XLVI"] = 46, s[46] = "XLVI";
		m["XLVII"] = 47, s[47] = "XLVII";
		m["XLVIII"] = 48, s[48] = "XLVIII";
		m["XLIX"] = 49, s[49] = "XLIX";
		m["L"] = 50, s[50] = "L";
	}

	bool iseven(long long x) {
		if (x % 2 == 0)
			return 1;
		return 0;
	}
	void selection(string arr1[], int arr2[], int n) {
		for (int i = 0; i < n; i++) {
			int w = i;
			bool ll = true;
			int r = 1000;
			for (int k = i + 1; k < n; k++) {
				if (arr1[k] == "Charles" || ll == false) {
					if (arr1[k] == "Charles" && r > arr2[k])
						w = k, r = arr2[k];
					ll = false;
				} else if (arr1[w].size() >= arr1[k].size()) {
					if (arr1[w].size() > arr1[k].size()
							|| (arr1[w].size() == arr1[k].size()
									&& arr2[w] >= arr2[k]))
						w = k;
				}
			}
			swap(arr1[w], arr1[i]);
			swap(arr2[w], arr2[i]);
		}
	}
	vector<string> getSortedList(vector<string> kings) {
		/*
		 "Louis IX", "Louis VIII"
		 "Louis VIII", "Louis IX"
		 */
		markz();
		vector<pair<string, pair<int, string> > > ret;
		int sz = kings.size();
		FO(i,0 ,sz) {
			stringstream s(kings[i]);
			string s1, s2;
			s >> s1;
			s >> s2;
			ret.PB(MP(s1, MP(m[s2], s2)));
		}

		SORT(ret);

		vector<string> TOT;
		FO(i,0, sz) {
			TOT.push_back(ret[i].first + " " + ret[i].second.second);
		}

		return TOT;
	}
};
