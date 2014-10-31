#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
#define fore(i,a) for(int i=0;i<a.size();i++)
#define FOR(q,e) for(int q=0;q<e;q++)
class WordCompositionGame {
public:
	int find(vector<string> x, string y) {
		int i = 0;
		for (i = 0; i < x.size(); i++)
			if (y == x[i])
				return i;
		return -1;
	}
	string score(vector<string> listA, vector<string> listB,
			vector<string> listC) {
		int x = 0, y = 0, z = 0;
		fore (i,listA) {
			bool check1 = true, check2 = true;
			if (find(listB, listA[i]) != -1 && find(listC, listA[i]) != -1) {
				check1 = false;
				check2 = false;
				listB.erase(listB.begin() + find(listB, listA[i]));
				listC.erase(listC.begin() + find(listC, listA[i]));
				listA.erase(listA.begin() + i);
				i--;
				cout << "ereererer" << endl;
			} else if (find(listB, listA[i]) != -1) {
				check1 = false;
				listB.erase(listB.begin() + find(listB, listA[i]));
				listA.erase(listA.begin() + i);
				i--;
			} else if (find(listC, listA[i]) != -1) {
				check2 = false;
				listC.erase(listC.begin() + find(listC, listA[i]));
				listA.erase(listA.begin() + i);
				i--;
			}
			if (check1 == true && check2 == true)
				x += 3;
			else if ((check1 == false && check2 == true) || (check2 == false
					&& check1 == true))
				x += 2;
			else
				x += 1;
		}
		fore (i,listB) {
			bool check1 = true, check2 = true;
			if (find(listA, listB[i]) != -1 && find(listC, listB[i]) != -1) {
				check1 = false;
				check2 = false;
				listA.erase(listA.begin() + find(listA, listB[i]));
				listC.erase(listC.begin() + find(listC, listB[i]));
				listB.erase(listB.begin() + i);
				i--;
				cout << "ereererer" << endl;
			} else if (find(listA, listB[i]) != -1) {
				check1 = false;
				listA.erase(listA.begin() + find(listA, listB[i]));
				listB.erase(listB.begin() + i);
				i--;
			} else if (find(listC, listB[i]) != -1) {
				check2 = false;
				listC.erase(listC.begin() + find(listC, listB[i]));
				listB.erase(listB.begin() + i);
				i--;
			}
			if (check1 == true && check2 == true)
				y += 3;
			else if ((check1 == false && check2 == true) || (check2 == false
					&& check1 == true))
				y += 2;
			else
				y += 1;
		}
		fore (i,listC) {
			bool check1 = true, check2 = true;
			if (find(listB, listC[i]) != -1 && find(listA, listC[i]) != -1) {
				check1 = false;
				check2 = false;
				listB.erase(listB.begin() + find(listB, listC[i]));
				listA.erase(listA.begin() + find(listA, listC[i]));
				listC.erase(listC.begin() + i);
				i--;
				cout << "ereererer" << endl;
			} else if (find(listB, listC[i]) != -1) {
				check1 = false;
				listB.erase(listB.begin() + find(listB, listC[i]));
				listC.erase(listC.begin() + i);
				i--;
			} else if (find(listA, listC[i]) != -1) {
				check2 = false;
				listA.erase(listA.begin() + find(listA, listC[i]));
				listC.erase(listC.begin() + i);
				i--;
			}
			if (check1 == true && check2 == true)
				z += 3;
			else if ((check1 == false && check2 == true) || (check2 == false
					&& check1 == true))
				z += 2;
			else
				z += 1;
		}
		cout << x << y << z << endl;
		string res = "";
		char s = '/';
		cout << "S" << s << endl;
		res += int(x + '0');
		res += s;
		res += int(y + '0');
		res += s;
		res += int(z + '0');
		return res;
	}
};
