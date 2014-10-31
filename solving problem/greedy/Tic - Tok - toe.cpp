//http://www.spoj.com/problems/TOE2/
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	string word;
	while(cin>>word){
		int xx = 0;
		int oo = 0;
		if(word == "end")
			return 0;
		for(int i=0;i<word.size();i++){
			if(word[i] == 'O')
			    oo++;
			else if (word[i] == 'X')
			    xx++;
		}
		int x = 0;
		int o = 0;
		
		if(word[0] == word[1] && word[0] == word[2]){
			if(word[0]=='O')
				o++;
			else if (word[0] == 'X')
				x++;
		}
		if(word[3] == word[4] && word[3] == word[5]){
			if(word[3] == 'O')
				o++;
			else if (word[3] == 'X')
				x++;
		}
		if(word[6] == word[7] && word[6] == word[8]){
			if(word[6] == 'O')
				o++;
			else if (word[6] == 'X')
				x++;
		}
		if(word[0] == word[3] && word[0] == word[6]){
		 	if(word[0] == 'O')
		 		o++;
		 	else if (word[0] == 'X')
		 		x++;
		}
		if(word[1] == word[4] && word[1] == word[7]){
			if(word[1] == 'O')
				o++;
			else if (word[1] == 'X')
				x++;
		}
		if(word[2] == word[5] && word[2] == word[8]){
			if(word[2] == 'O')
				o++;
			else if (word[2] == 'X')
				x++;
		}
		if(word[0] == word[4] && word[0] == word[8]){
			if(word[0] == 'O')
				o++;
			else if (word[0] == 'X')
				x++;
		}
		if(word[2] == word[4] && word[2] == word[6]){
			if(word[2] == 'O')
				o++;
			else if (word[2] == 'X')
				x++;
		}
		//cout << x << o << xx << oo <<endl;
		if((oo == xx || oo+1 == xx ) && (x >= 1 || o >= 1 || xx+oo == word.size())){
			if ( x == 1 && o == 0)
				cout<<"valid"<<endl;
			else if (x == 2 && o == 0)
				cout<<"valid"<<endl;
			else if (o == 1 && x == 0 && oo == xx)
				cout<<"valid"<<endl;
			else if ( x == 0 && o == 0)
				cout<<"valid"<<endl;
			else if (xx == 1 && oo == 0)
				cout<<"valid"<<endl;
			else
				cout<<"invalid"<<endl;
		}else 
			cout << "invalid"<<endl;
	}
    return 0;
}
