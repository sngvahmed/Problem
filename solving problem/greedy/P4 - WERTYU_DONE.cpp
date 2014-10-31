#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <math.h>
using namespace std;
int main()
{
    string s;
    while(getline(cin,s))
    {
            string ss="";
            string a="'";
            string final="";
            for(int i=0;i<s.size();i++)
            {
                    if(s[i]=='W')
                       final+="Q";
                    else if(s[i]=='E')
                       final+="W";
                    else if(s[i]=='R')
                       final+="E";
                    else if(s[i]=='R')
                       final+="E";
                    else if(s[i]=='T')
                       final+="R";
                    else if(s[i]=='Y')
                       final+="T";
                    else if(s[i]=='U')
                       final+="Y";
                    else if(s[i]=='I')
                       final+="U";
                    else if(s[i]=='O')
                       final+="I";
                    else if(s[i]=='P')
                       final+="O";
                    else if(s[i]=='[')
                       final+="P";
                    else if(s[i]==']')
                       final+="[";
                    else if(s[i]=='\\')
                       final+="]";
                    else if(s[i]=='S')
                       final+="A";
                    else if(s[i]=='D')
                       final+="S";
                    else if(s[i]=='F')
                       final+="D";
                    else if(s[i]=='G')
                       final+="F";
                    else if(s[i]=='H')
                       final+="G";
                    else if(s[i]=='J')
                       final+="H";
                    else if(s[i]=='K')
                       final+="J";
                    else if(s[i]=='L')
                       final+="K";
                    else if(s[i]==';')
                       final+="L";
                    else if(s[i]==a[0])
                       final+=";";
                   else if(s[i]=='X')
                       final+="Z";
                    else if(s[i]=='C')
                       final+="X";
                    else if(s[i]=='V')
                       final+="C";
                    else if(s[i]=='B')
                       final+="V";
                    else if(s[i]=='N')
                       final+="B";
                    else if(s[i]=='M')
                       final+="N";
                    else if(s[i]==',')
                       final+="M";
                    else if(s[i]=='.')
                       final+=",";
                    else if(s[i]=='/')
                       final+=".";
                    else if(s[i]==a[0])
                       final+=";";
                   else if(s[i]==' ')
                       final+=" ";
                   else if(s[i]=='1')
                       final+="~";
                   else if(s[i]=='=')
                       final+="-";
                   else if(s[i]=='1')
                       final+="~";
                   else if(s[i]=='-')
                       final+="0";
                   else if(s[i]=='0')
                       final+="9";
                   else if(s[i]=='9')
                       final+="8";
                   else if(s[i]=='8')
                       final+="7";
                   else if(s[i]=='7')
                       final+="6";
                   else if(s[i]=='6')
                       final+="5";
                   else if(s[i]=='5')
                       final+="4";
                   else if(s[i]=='4')
                       final+="3";
                   else if(s[i]=='3')
                       final+="2";
                   else if(s[i]=='2')
                       final+="1";
            }
            cout<<final<<endl;
    }


    system("pause");
    return 0;
}
