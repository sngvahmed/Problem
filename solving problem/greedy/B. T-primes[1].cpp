/*
 * B. T-primes.cpp
 * http://codeforces.com/problemset/problem/230/B
 *      Author: ahmed
 */
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
#define fore(i,a) for(int i = 0;i<a.size();i++)
#define FOR(i,a) for(int i=0;i<a;i++)
using namespace std;
bool isprime(int s) {
	if ((s % 2 == 0) || (s % 3 == 0) || (s % 4 == 0) || (s % 5 == 0) || (s % 6
			== 0) || (s % 7 == 0) || (s % 8 == 0) || (s % 9 == 0))
		return false;
	else if ((s / 1 == s) && (s / s == 1))
		return true;
}
int is_prime(long long s) {
	//cout<<"here"<<endl;
	int w = 1;
	if (s == 1)
		return 1;
	for (int i = 2; i <= s; i++)
		if (s % i == 0) {
			w++;
		}
	//	cout<<w<<endl;
	return w;
}

int main() {
	long long x;
	cin >> x;
	long long num[x];
	int s[2] = { 0 };
	for (int i = 0; i < x; i++)
		cin >> num[i];
	for (int i = 0; i < x; i++) {
		//		cout<<num[i]<<endl;
		if (isprime(is_prime(num[i])) == false)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}//cout<<s[0]<<" " <<s[1]<<endl;
	/*for(int i=0;i<s[0];i++)
	 cout<<"YES"<<endl;
	 for(int i=0;i<s[1];i++)
	 cout<<"NO"<<endl;*/

	return 0;
}

