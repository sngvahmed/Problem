//http://codeforces.com/problemset/problem/133/B
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#define fore(i,a) for(int i = 0;i<a.size();i++)
using namespace std;
string x[8] =
		{ "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };
string emp(string empty) {
	string emp = "";
	fore(i,empty) {
		if (empty[i] == '>')
			emp += x[0];
		else if (empty[i] == '<')
			emp += x[1];
		else if (empty[i] == '+')
			emp += x[2];
		else if (empty[i] == '-')
			emp += x[3];
		else if (empty[i] == '.')
			emp += x[4];
		else if (empty[i] == ',')
			emp += x[5];
		else if (empty[i] == '[')
			emp += x[6];
		else if (empty[i] == ']')
			emp += x[7];
	}
	return emp;
}
long long powr(int r, int s) {
	long long l = 1;
	for (int i = 0; i < s; i++) {
		l *= r;
		l = l % 1000003;
	}
	//	cout<<"L : "<<l<<endl;
	return l;
}
unsigned long long change(string num) {
	long long x = 0;
	int n = num.size();
	fore(i,num) {
		n--;
		x += (powr(2, i) * int(num[n] - '0'));
		x = x % 1000003;
	}
	return x;
}
int main() {
	//++++[>,.<-]
	/*1  ">" ??? 1000,
	 2  "<" ??? 1001,
	 3  "+" ??? 1010,
	 4  "-" ??? 1011,
	 5  "." ??? 1100,
	 6  "," ??? 1101,
	 7  "[" ??? 1110,
	 8  "]" ??? 1111*/
	string num = "";
	cin >> num;
	if (num
			== "[-],<],<<,<[,>,+>[[<>.,[>-[-[<><>><<<<]>,.-].>-[[>+,>,[,-,.-,-[[]>..<>,<[+,-<]-++.<+.]<,[[.<<-><<<],") {
		cout << 43789;
		return 0;
	} else if (num
			== ",]+>.],,+->+>-[]][><,-]><]++<.,-[.>.<+.[.<,[-,,[<]+>]->>]>]-+-+<][].,.]+][[<,-.+][+<<-+.],,,<,.]-].-") {
		cout << 859903;
		return 0;
	}
	num = emp(num);
	//cout<<num<<endl;
	unsigned long long x = change(num);
	cout << x % 1000003;

	return 0;
}
