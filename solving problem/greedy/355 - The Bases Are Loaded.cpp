//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=291
#include<iostream>
#include<cmath>
#include<cstring>
#include<ctype.h>
using namespace std;
long long power(int x , int y){
    long long sum = 1;
    for(int i=0;i<y;i++)
        sum += sum*x;
    return sum;
}
long long to_desimal(string number, long long base) {
	long long  a, b, sum = 0;
	int size;
	size = number.size();
	for (int i = 0; i < size; i++) {
			if (isdigit(number[size - i - 1]) == true) {
				b = (int) (number[size - i - 1]) - (int) ('0');
			} else {
				b = ((int) (number[size - i - 1]) - (int) ('A')) + 10;
			}
		a = pow((double) (base), (double) (i));
		if (b < base) {
			sum += a * b;
		} else {
			return -1;
		}
	}

	return sum;
}
string to_any_base(long long number, long long base) {
	char x;
	long long r;
	string final_number = "";
	while (number != 0) {
		r = number % base;
		number = number / base;
		if (r >= 10) {
			x = (char) (((r) - 10) + (int) ('A'));
		} else {
			x = r + int('0');
		}
		final_number = x + final_number;
	}
	if ( final_number == "" )
        final_number = "0";
	return final_number;
}
bool check(string word){
    for(int i=0;i<word.size();i++){
        if(('A'<=word[i] && word[i]<='Z') || ('0'<=word[i] && word[i]<='9'))
            continue;
        else
            return false;
    }
    return true;
}
int main(){
	string number1;
	//2 10 10101
	long long  basefrom , baseto, x, s;
	while(cin>>basefrom>>baseto>>number1){
        if (!check(number1))
            cout<<number1<<" is an illegal base " << basefrom <<" number";
        else {
                x = to_desimal(number1, basefrom);
                //cout << x << endl;;
                if (x == -1)
                    cout<<number1<<" is an illegal base " << basefrom <<" number";
                else if (to_any_base(x, baseto) != "")
                    cout << number1 << " base " << basefrom << " = " <<to_any_base(x, baseto)<<" base "<<baseto;
            }
            cout << endl;
        }

	return 0;
}
