#include "bits/stdc++.h"
#include <functional>
#include <ext/numeric> 
using namespace std;

#define SZ(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MMS(x, v) memset(x, v, sizeof(x))

string var = "";
void if_statement() {

	string ifstatement = "", commonState = "", rem = "";

	for (int i = 0; i < SZ(var); i++) {
		if (var[i] == '<' && !(SZ(ifstatement))) {
			while (var[i] != '>')
				ifstatement += var[i], i++;
			ifstatement += '>';
		} else if (var[i] == '-' && var[i + 1] == '>') {
			i++, i++;
			while (var[i] != '|')
				commonState += var[i], i++;
			i += commonState.size();
			while (i < SZ(var))
				rem += var[i], i++;
			rem.erase(rem.begin());
		}
	}
	cout << ifstatement << " ->" << commonState << "[" << rem << "]" << endl;
}

void ident_list() {
	string idenlist = "", commonState = "", rem = "";

	for (int i = 0; i < SZ(var); i++) {
		if (var[i] == '<' && (!(SZ(idenlist)))) {
			while (var[i] != '>')
				idenlist += var[i], i++;
			idenlist += '>';
		} else if (var[i] == '-' && var[i + 1] == '>') {
			i++, i++;
			while (var[i] != '|')
				commonState += var[i], i++;
			i += commonState.size();
			while (i < SZ(var))
				rem += var[i], i++;
			rem.erase(rem.begin());
		}
	}
	cout << idenlist << " -> <" << commonState.substr(1, SZ(commonState) - 2)
			<< "> {," << rem << "}" << endl;

}

//<term> -> <term> * <factor> | <term> / <factor> | <term> % <factor>

int howmany(char x) {
	int mn = 0;
	for (int i = 0; i < SZ(var); i++)
		if (var[i] == '|')
			mn++;
	return mn;
}
void mulitTerm() {
	var += '|';
	stringstream ss;
	char sm;
	string term, fact, tmp;
	vector<char> vr;

	ss << var;

	ss >> term, ss >> tmp;

	while (!ss.eof())
		ss >> tmp, ss >> sm, vr.pb(sm), ss >> fact, ss >> sm;

	cout << term << " -> " << term << " (";
	for (int i = 0; i < SZ(vr); i++) {
		if (i == SZ(vr) - 1)
			cout << vr[i];
		else
			cout << vr[i] << "|";
	}
	cout << ") " << fact.substr(0, SZ(fact) - 1);
}

int main() {
	freopen("input.txt", "rt", stdin);
	string BNF;

	while (getline(cin, var)) {

		string sub = var.substr(1, var.find('>') - 1);
		if (sub == "if_stmt" || sub == "expr") {
			if_statement();
		} else if (sub == "ident_list") {
			ident_list();
		} else if (sub == "term") {
			mulitTerm();
		}
	}
	return 0;
}
