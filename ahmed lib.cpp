//============================================================================
// Author      : Ahmed nasser
// Version     :
// Copyright   : A. Train and Peter
// Description : Hello World in C++, Ansi-style
//============================================================================
//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=9
//http://ideone.com/WGakse
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

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<string> vs;
typedef vector<int> vi;
//***********       Remove zero from Int ***********
string removezero(string num) {
	string s = "";
	FO(i,0,num.size()) {
		if (num[i] != '0')
			s += num[i];
	}
	return s;
}


///////////////////////////////////////////Get the Day Data 
char *getName(int day){ //returns the name of the day
   switch(day){
      case 0 :return("Sunday");
      case 1 :return("Monday");
      case 2 :return("Tuesday");
      case 3 :return("Wednesday");
      case 4 :return("Thursday");
      case 5 :return("Friday");
      case 6 :return("Saturday");
      default:return("");
   }
}

int getDayNumber(int dd,int mm,int yy){ //retuns the day number
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    yy -= mm < 3;
    return (yy + yy/4 - yy/100 + yy/400 + t[mm-1] + dd) % 7;
}
//////////////////////////////////////////////////////////////


// **************************************************
//************** convert from int t o decomal *******
int TOint(string num) {
	stringstream ss;
	int n = 0;
	ss << num, ss >> n;
	return n;
}
string TOstring(int num) {
	stringstream ss;
	string n = "";
	ss << num, ss >> n;
	return n;
}
// ***************************************************
//******************************** Base Convert ******
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

//***************** FILE INPUT ******************
void ANYFILE() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "rt", stdin);
	freopen("o.txt", "wt", stdout);
#endif
}

//***********************************************
//**** PRIME WITH O(n) **************************
bool primes[1000001];
int e = 0;
int arr[10000001];
void initPrimes() {
	memset(primes, true, sizeof(primes));
	primes[0] = primes[1] = false;
	for (int i = 2; i <= 1000000; i++) {
		if (primes[i]) {
			arr[e] = i;
			e++;
			for (int j = 2; i * j <= 1000000; j++)
				primes[i * j] = false;
		}
	}
}
//**********************************************
//*********** GET THE DIVISION *****************

unsigned long long int SumOfDivisors(int num) {
	int sum = 0;
	for (int i = 1; i * i <= num; i++)
		sum += (num % i) ? 0 : ((i * i == num) ? i : i + num / i);
	return sum;
}
//*********************************************
//********* SET DIVISOR ***********************
void set() {
	set<int> x;
	int myints[] = { 10, 20, 30, 40, 50 };
	set<int> second(myints, myints + 5);
	int d = 0;
	for (set<int>::iterator it = myints.begin(); it != myints.end(); it++) {
		if (d < *it) {
			d = *it;
			//to get the maxium;
		}
		if (d > *it) {
			d = *it;
//			to getthe minum;
		}
		cout << *it << " ";
	}
}
//**************************************************
//****************   SORT    ***********************
// SELECTION SORT :::::::
void selection(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int w = i;
		for (int k = i + 1; k < n; k++) {
			if (arr[w] < arr[k])
				w = k;
		}
		swap(arr[w], arr[i]);
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}
}
// BINARY SORT ::::::::::
bool BinarySearch(vector<T> t, T key, int Begin, int end) {
	if (t[Begin] == key || t[end] == key)
		return true;
	if (t[(Begin + end) / 2] <= key)
		BinarySearch(t, key, Begin, end / 2);
	else
		BinarySearch(t, key, end / 2, end);
	return false;
}
// *************************************************
// ************* STRING SUM ***********************
string sum(string num1, string num2) {
	//		cout << "may be wrong " << endl;
	string result;
	result = num1;
	// Check which integer is longer
	//----------------------------
	for (int i = 0; i < max(num1.size(), kelma.size()); i++) {
		if (i < num1.size() && i < kelma.size()) {
			int sum = int(num1[i]) % 48 + kelma[i] % 48;
			if (sum <= 9)
				result[i] = sum + 48;
			else {
				result[i] = sum + 48 - 10;
				if (i < kelma.size() - 1) {
					kelma[i + 1] += 1;
				} else if (i < num1.size() - 1) {
					num1[i + 1] += 1;
				} else {
					result += '1';
				}
			}
		} else if (i >= kelma.size()) {
			//				cout << "secound step :: " << result << endl;
			//cout << num.num1[i] << endl;
			result[i] = num1[i];
			if (i == num1.size() - 1 && result[i] > '9') {
				result[i] -= 10;
				result += '1';
			} else if (result[i] > '9') {
				result[i] -= 10;
				num1[i + 1] += 1;
			}
		} else {
			//				cout << "third step :: " << result << endl;
			//cout << num1[i] << endl;
			result[i] = kelma[i];
			if (i == kelma.size() - 1 && result[i] > '9') {
				//					cout << "herererer" << endl;
				result[i] -= 10;
				result += '1';
			} else if (result[i] > '9') {
				result[i] -= 10;
				kelma[i + 1] += 1;
			}
		}
	}
	return result;
}
//*************************************
	cout << setprecision(12) << fixed << (re * 100) / double(n * 100);

