#include <iostream>
#include <vector>
using namespace std;
class  Pronunciation{
	public:
	bool is_lower(char s){
		if(int(s)>=92&&int(s)<=122)
			return true;
		return false;
	}
	bool characrtistic(char s){
		if(s=='i' || s=='I' || s=='o' || s=='O' || s=='u' || s=='U' || s=='a' || s=='A' || s=='e' || s=='E')
			return true;
		return false;
	}

	string canPronounce(vector <string> words){
		for(int i = 0 ; i<words.size() ; i++){
			for(int q = 1 ; q<words[i].size() ; q++){
				if(	characrtistic(words[i][q])  && characrtistic(words[i][q-1])  && is_lower(words[i][q])
				&& is_lower(words[i][q-1]))
					return words[i];
			}
			for(int q = 2 ; q<words[i].size() ; q++){
				if(	!characrtistic(words[i][q])  && !characrtistic(words[i][q-1])  && !characrtistic(words[i][q-2]))
					return words[i];
			}
		}
		return "";
	}




};
