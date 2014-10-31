#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#define fr(n) for(int i=0;i<n;i++)
using namespace std;

int main() {
	string name;
	cin >> name;
	string result = "";
	fr(name.size()) {
		//if(name[i]==name[i+1]){
		int count = 0;
		for (int q = i; q < name.size(); q++) {
			if (name[i] == name[q])
				count++;
			else
				break;
			if (count == 9)
				break;
		}
		//cout << count << endl;
		result += count + '0';
		result += name[i];
		//cout << name[i] << endl;
		i += count - 1;
		/*		}else{
		 result+='1';
		 result+=name[i];
		 }*/
	}
	//1sddq1
	//cout << result << endl;
	string ret = "";
	for (int i = 0; i < result.size(); i++) {
		if (result[i] != '1') {
			//cout << "ere" << endl;
			ret += result[i];
		} else {
			int e;
			ret += '1';
			for (e = i; e < result.size(); e += 2) {
				if (result[e - 1]) {
					ret += '1';
					break;
				}
				if (result[e] == '1' && result[e + 1] == '1') {
					ret += '1';
					ret += '1';
				} else if (result[e] == '1') {
					ret += result[e + 1];
				} else if (result[e] == '2' || result[e] == '3' || result[e]
						== '4' || result[e] == '5' || result[e] == '6'
						|| result[e] == '7' || result[e] == '8' || result[e]
						== '9') {
					break;
				}
			}
			ret += '1';
			i = e - 1;
			;
		}
	}
	cout << ret;
	system("pause");
	return 0;
}

