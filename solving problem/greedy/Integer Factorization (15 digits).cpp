//http://www.spoj.com/problems/FACT0/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
vector<unsigned long long int>fact;
unsigned long long int trial_division_sqrt(unsigned long long int n) {
    unsigned long long int x, x_squared;
    for(x=2, x_squared=4;
        x_squared > 2*x - 1 && x_squared <= n;
        x++, x_squared += 2*x - 1)
    {
        if ((n % x) == 0) {
            return x;
        }
    }
    return 0;
}
void El_Mas2la(unsigned long long int num){
    int n = 0;
    fact.push_back(num);
    while(true){
        //cout << fact[n] << " " << n << " " << fact.size() << " " << num << endl;
        //cin.get();
        if ( n == fact.size() )
            break;

        unsigned long long int x = trial_division_sqrt(num);
        if ( x != 0){
            fact.push_back(x);
            fact.push_back(num / x);
            fact.erase(fact.begin() + n);
            num = fact[n];
        }else if ( x == 0)
            {n++; num = fact[n]; }

    }
}
int main()
{
    unsigned long long int temp;
    while(cin >> temp){
    if (temp == 0) break;
    El_Mas2la(temp);
    sort(fact.begin() , fact.end());
    int i;
    //for(int n=0 ; n < fact.size();n++)cout << fact[n] << " ";
    //cout << endl;
    for(int n=0 ; n < fact.size();n++){
        if(n != 0)
            cout << " ";
        i = n;
        int sum = 0;
        while(fact[i] == fact[n] && i < fact.size()){
            sum++ ;
            i++;
        }
        cout << fact[n]  <<"^" << sum;
        n = i - 1;
    }
        fact.clear();
        cout << endl;
    }
    return 0;
}

