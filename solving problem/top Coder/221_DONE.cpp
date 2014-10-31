//189
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include<stdio.h>
#include<string.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define Fors(i,a) for(int i=0;i<a.size();i++)
typedef long long ll;
typedef unsigned long long ull;
class EqualSubstrings {
public:
	vector<string> getSubstrings(string str) {
		int count[2] = { 0, 0 };
		Fors(i,str) {
			if (str[i] == 'a')
				count[0]++;
			else
				count[1]++;
		}
		vector<string> x;
		x.push_back("");
		x.push_back("");
		if (count[1] > count[0]) {
			int co = 0;
			Fors(i,str) {
				if (co == count[0]) {
					co = i;
					break;
				}
				if (str[i] == 'b')
					co++;
			}
			Fors (i,str) {
				if (i < co - 1) {
					x[0] += str[i];
				} else
					x[1] += str[i];
			}
		} else if (count[2] >= count[1]) {
			int co = 0;
			Fors(i,str) {
				if (co == count[1]) {
					co = i;
					break;
				}
				if (str[i] == 'b')
					co++;
			}
			Fors (i,str) {
				if (i < co) {
					x[0] += str[i];
				} else
					x[1] += str[i];
			}
		}
		if (x[1].size() == 0)
			swap(x[0], x[1]);
		return x;
	}
};

