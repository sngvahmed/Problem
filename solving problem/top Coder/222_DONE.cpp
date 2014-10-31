//75%
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
#define Fors(k,a) for(int i=0;i<a.size();i++)
typedef long long ll;
typedef unsigned long long ull;
class TextCompressor {
public:
	string longestRepeat(string sourceText) {
		string x = "";
		while (sourceText.size() != 0) {
			for (int i = 0; i < sourceText.size(); i++) {
				string result = "";
				for (int q = 0; q < i; q++)
					result += sourceText[q];
				string resultre = "";
				for (int q = i; q < sourceText.size(); q++)
					resultre += sourceText[q];

				//			cout << result << " " << resultre << endl;
				//			cout << resultre.find(result) << " " << result.size() << endl;
				if (resultre.find(result) < -1 && result.size() != 0)
					if (result.size() > x.size()) {
						x = result;
						//						cout << x;
						//						cout << "here " << endl;
						cout << x << endl;
					}
			}
			sourceText.erase(sourceText.begin());
		}
		return x;
	}

};

