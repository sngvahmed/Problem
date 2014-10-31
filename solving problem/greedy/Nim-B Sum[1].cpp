#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stdio.h>
using namespace std;
typedef vector<string> vs;
typedef unsigned long long lln;
long long anybasetoanybase(long long num, long long tomode, long long mode)//it will take the number and base you will input and base you want it
{
	long long w = 1, x, z = 1, sum = 0, i;
	while (num != 0) {
		x = num % 10;
		num = num / 10;
		i = w * x;
		sum = sum + i;
		w = w * mode;
	}
	w = 1, z = 1, i = 1;
	long long sum2 = 0;
	while (sum != 0) {
		x = sum % tomode;
		w = x * z;
		sum2 = sum2 + w;
		sum = sum / tomode;
		z = z * 10;

	}
	return sum2;
}
int main() {

	long long x;
	cin >> x;
	long long h = x;
	while (x--) {
		if (x == h - 1) {
			string d;
			getline(cin, d);
		}
		string word;
		getline(cin, word);
		long long count = 4;
		stringstream ss;
		ss << word;
		long long co;
		ss >> co;
		long long base;
		ss >> base;
		long long num1;
		long long num2;
		ss >> num1;
		ss >> num2;
		long long re1 = anybasetoanybase(num1, base, 10);
		long long re2 = anybasetoanybase(num2, base, 10);
		string result = "";
		while (true) {
			if (re1 == 0 && re2 == 0)
				break;
			//1111011 ¤ 111001000
			long long num11 = re1 % 10;
			long long num22 = re2 % 10;
			long long sum = num11 + num22;
			if (sum < base) {
				stringstream dd;
				dd << sum;
				string q;
				dd >> q;
				result += q;
			} else {
				sum = base - sum;
				stringstream dd;
				dd << sum;
				string q;
				dd >> q;
				result += q;
			}
			re1 = re1 / 10;
			re2 = re2 / 10;
		}
		string res = "";
		for (long long i = result.size() - 1; i >= 0; i--)
			if(result[i]!='-')
			res += result[i];
		stringstream eee;
		eee << res;
		long long l;
		eee >> l;
		l = anybasetoanybase(l, 10, base);
		cout << co << " " << l << endl;
	}
	return 0;
}
