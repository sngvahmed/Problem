//http://www.spoj.com/problems/TOE1/
#include iostream
#include vector
#include sstream
using namespace std;

int main()
{
	int i ;
	cini;
	while(i--){
		string word;
		string w1,w2,w3;
        cinw1w2w3;
		word[0] = w1[0];
		word[1] = w1[1];
		word[2] = w1[2];
		word[3] = w2[0];
		word[4] = w2[1];
		word[5] = w2[2];
		word[6] = w3[0];
		word[7] = w3[1];
		word[8] = w1[2];
		int xx = 0;
		int oo = 0;
		for(int i=0;iw1.size();i++){
			if(w1[i] == 'O')
			    oo++;
			else if (w1[i] == 'X')
			    xx++;
		}

		for(int i=0;iw2.size();i++){
			if(w2[i] == 'O')
			    oo++;
			else if (w2[i] == 'X')
			    xx++;
		}

		for(int i=0;iw3.size();i++){
			if(w3[i] == 'O')
			    oo++;
			else if (w3[i] == 'X')
			    xx++;
		}
		int x = 0;
		int o = 0;
		if(w1[0] == w1[1] && w1[0] == w1[2]){
			if(w1[0]=='O')
				o++;
			else if (w1[0] == 'X')
				x++;
		}
		if(w2[0] == w2[1] && w2[0] == w2[2]){
			if(w2[0] == 'O')
				o++;
			else if (w2[0] == 'X')
				x++;
		}
		if(w3[0] == w3[1] && w3[0] == w3[2]){
			if(w3[0] == 'O')
				o++;
			else if (w3[0] == 'X')
				x++;
		}
		if(w1[0] == w2[0] && w1[0] == w3[0]){
		 	if(w1[0] == 'O')
		 		o++;
		 	else if (w1[0] == 'X')
		 		x++;
		}
		if(w1[1] == w2[1] && w1[1] == w3[1]){
			if(w1[1] == 'O')
				o++;
			else if (w1[1] == 'X')
				x++;
		}
		if(w1[2] == w2[2] && w1[2] == w3[2]){
			if(w1[2] == 'O')
				o++;
			else if (w2[2] == 'X')
				x++;
		}
		if(w1[0] == w2[1] && w1[0] == w3[2]){
			if(w1[0] == 'O')
				o++;
			else if (w1[0] == 'X')
				x++;
		}
		if(w1[2] == w2[1] && w1[2] == w3[0]){
			if(w1[2] == 'O')
				o++;
			else if (w1[2] == 'X')
				x++;
		}
		cout  x  o  xx  oo endl;
		if((oo == xx  oo+1 == xx )){
			if ( x == 1 && o == 0 && xx == oo+1)
				coutyesendl;
			else if ( x == 2 && o == 0 )
				coutyesendl;
			else if (o == 1 && x == 0 && oo == xx)
				coutyesendl;
			else if ( x == 0 && o == 0)
				coutyesendl;
			else if (xx == 1 && oo == 0 )
				coutyesendl;
			else if (xx == 0 && oo == 0)
			    coutnoendl;
   			else
				coutnoendl;
		}else 
			cout  noendl;
	}
    return 0;
}
