//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=283&mosmsg=Submission+received+with+ID+1246036
#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORE(n,a,b) for(int n=a;n<b;n++)
using namespace std;
int main(){
    map<char,string>encode;
    map<string,char>decode;
    //PUEL

     encode[','] = ".-.-";         encode['?'] = "----";          encode['_'] = "..--";              encode['.'] = "---.";
     encode['A'] = ".-";           encode['H'] = "....";          encode['O'] = "---";               encode['V'] = "...-";
     encode['B'] = "-...";         encode['I'] = "..";            encode['P'] = ".--.";              encode['W'] = ".--";
     encode['C'] = "-.-.";         encode['J'] = ".---";          encode['Q'] = "--.-";              encode['X'] = "-..-";
     encode['D'] = "-..";          encode['K'] = "-.-";           encode['R'] = ".-.";               encode['Y'] = "-.--";
     encode['E'] = ".";            encode['L'] = ".-..";          encode['S'] = "...";               encode['Z'] = "--..";
     encode['F'] = "..-.";         encode['M'] = "--";            encode['T'] = "-";
     encode['G'] = "--.";          encode['N'] = "-.";            encode['U'] = "..-";
     //******************************************************************************************************************
     decode[".-.-"] = ',';        decode["----"] = '?';          decode["..--"] = '_';              decode["---."] = '.';
     decode[".-"]   = 'A';        decode["...."] = 'H';          decode["---"] = 'O';               decode["...-"] = 'V';
     decode["-..."] = 'B';        decode[".."] = 'I';            decode[".--."] = 'P';              decode[".--"] = 'W' ;
     decode["-.-."] = 'C';        decode[".---"] = 'J';          decode["--.-"] = 'Q';              decode["-..-"] = 'X';
     decode["-.."]  = 'D';        decode["-.-"] = 'K';           decode[".-."] = 'R';               decode["-.--"] = 'Y';
     decode["."]    = 'E';        decode[".-.."] = 'L';          decode["..."] = 'S';               decode["--.."] ='Z' ;
     decode["..-."] = 'F';        decode["--"] = 'M';            decode["-"] = 'T';
     decode["--."]  = 'G';        decode["-."] = 'N';            decode["..-"] = 'U';
     int x;
     scanf("%d",&x);
     int y = 0;
     while(x--){
        string s;
        cin >> s;
        string length = "";
        string code = "";
        for(int i=0;i<s.size();i++){
            length += char(encode[s[i]].size() + '0');
            code += encode[s[i]];
        }
        //cout << length << " " << code << endl;
        reverse(length.begin(),length.end());
        //reverse(code.begin(),code.end());
        //cout << length << " " << code << endl;
        s = "";
        int e = 0;
        for(int i=0;i<code.size();i++,e++){
            string t = "";
            for(int n = i + int(length[e]-'0')-1 ; n >=i; n--)
                t+=code[n];
            reverse(t.begin(),t.end());
            //cout << t << endl;
            s += decode[t];
            i = i + int(length[e]-'0')-1;
        }
        cout << ++y<<": "<<s<<endl;
     }

    return 0;
}
