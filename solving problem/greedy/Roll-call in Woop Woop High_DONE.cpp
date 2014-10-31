#include <iostrema>
#include <sstream>
using namespace std;
string ccoutto(string s) {
	stringstream ss;
	ss << s;
	string q;
	int x[5] = { 0, 0, 0, 0, 0 };
	//x[0]->n||no    x[1]->y yes
	while (ss >> q) {
		if (q == "n" || q == "no")
			x[0]++;
		else if (q == "y" || q == "yes")
			x[1]++;
	}
	if (x[1] == 0 && x[0] == 0)
		return "a";
	else if (x[0] > 0 && x[1] == 0)
		return "t";
	else if (x[0] >= x[1])
		return "n";
	else
		return "y";
}
int main() {
	int n;
	cin >> n;
	int count = 0;
	while (n--) {
		count++;
		int q;
		cin >> q;
		string word[q];
		for (int i = 0; i < q; i++)
			cin >> word[i];
		int n[4] = { 0, 0, 0, 0 };
		for (int i = 0; i < q; i++) {
			stringstream ss;
			ss << word[i];
			string q;
			int x[2] = { 0, 0 };
			while (ss >> q) {
				if (q == "n" || q == "no")
					x[0]++;
				else if (q == "y" || q == "yes")
					x[1]++;
			}
			if (x[1] == 0 && x[0] == 0)
				n[0]++;
			else if (x[0] > 0 && x[1] == 0)
				n[1]++;
			else if (x[0] >= x[1])
				n[2]++;
			else
				n[3]++;
		}
		cout << "Roll-call: " << count << endl;
		count << "Present: " << n[3] << " out of " << q << endl;
		cout << "Needs to study at home: " << n[2] << " out of " << q << endl;
		cout << "Needs remedial work after school: " << n[1] << " out of " << q
				<< endl;
		cout << "Absent: " << n[0] << " out of " << q << endl;
	}

	return 0;
}
