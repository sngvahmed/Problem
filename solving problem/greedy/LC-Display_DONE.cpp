// 1031.   LC-Display DONE
// http://acm.tju.edu.cn/toj/showp1031.html
#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void r1(int n, int s) {
	if (n == 1 || n == 3 || n == 5) {
		for (int i = 0; i < s+2; i++)
			cout << " ";
	} else if (n == 4 || n == 2) {
		for (int i = 0; i <  s+1; i++)
			cout << " ";
		cout << "|";
	}
}
void r2(int n, int s) {
	if (n == 1 || n == 3 || n == 5) {
		cout << " ";
		for (int i = 0; i < s; i++)
			cout << "-";
		cout << " ";
	} else if (n == 2) {
		for (int i = 0; i <=  s; i++)
			cout << " ";
		cout << "|";
	} else if (n == 4) {
		cout << "|";
		for (int i = 0; i <=  s; i++)
			cout << " ";
	}
}
void r3(int n, int s) {
	if (n == 1 || n == 3 || n == 5) {
	    cout << " ";
		for (int i = 0; i < s; i++)
			cout << "-";
        cout << " ";
	} else if (n == 2 || n == 4) {
		for (int i = 0; i <= s ; i++)
			cout << " ";
		cout << "|";
	}
}
void r4(int n,int s) {
	if (n == 1 || n == 5){
		for(int i=0;i<s+2;i++)
            cout << " ";
	}else if (n == 2){
		cout << "|";
        for(int i=0;i<s;i++)
            cout << " ";
        cout << "|";
	}else if (n == 3){
		cout << " ";
		for(int i=0;i<s;i++)
            cout << "-";
		cout << " ";
    }else if (n == 4){
		for(int i=0;i<=s;i++)
            cout << " ";
		cout << "|";
    }
}
void r5(int n,int s) {
	if (n == 1 || n == 3 || n == 5){
		cout <<" ";
		for(int i=0;i<s;i++)
            cout << "-";
		cout << " ";
	}else if (n == 2){
		cout << "|";
        for(int i=0;i<=s;i++)
            cout << " ";
	}else if (n == 4){
        for(int i=0;i<=s;i++)
            cout << " ";
        cout << "|";
    }
}
void r6(int n,int s) {
	if (n == 1 || n == 3 || n == 5){
		cout << " ";
		for(int i=0;i<s;i++)
            cout << "-";
		cout << " ";
	}else if (n == 2){
		cout << "|";
		for(int i=0;i<=s;i++)
            cout << " ";
	}else if (n == 4){
		cout << "|";
        for(int i=0;i<s;i++)
            cout << " ";
        cout << "|";
    }
}
void r7(int n,int s) {
	if (n == 1){
	    cout << " ";
		for(int i=0;i<s;i++)
            cout << "-";
        cout <<" ";
	}else if (n == 2 || n == 4){
        for(int i=0;i<=s;i++)
            cout << " ";
        cout << "|";
	}else if (n == 3 || n == 5){
        for(int i=0;i<s+2;i++)
            cout << " ";
    }
}
void r8(int n,int s) {
	if (n == 1 || n == 3 || n == 5){
		cout << " ";
        for(int i=0;i<s;i++)
            cout << "-";
        cout << " ";
	}else if (n == 2 || n == 4){
		cout << "|";
        for(int i=0;i<s;i++)
            cout << " " ;
        cout << "|";
    }
}
void r9(int n,int s) {
	if (n == 1 || n == 3 || n == 5){
		cout << " ";
        for(int i=0;i<s;i++)
            cout << "-";
        cout << " ";
    }else if (n == 2){
        cout << "|";
        for(int i=0;i<s;i++)
            cout << " " ;
        cout << "|";
    }else if (n == 4){
        for(int i=0;i<=s;i++)
            cout << " ";
        cout << "|";
    }
}
void r0(int n,int s) {
	if (n == 1 || n == 5){
		cout << " ";
        for(int i=0;i<s;i++)
            cout << "-";
        cout << " ";
	}else if (n == 2 || n == 4){
        cout << "|";
        for(int i=0;i<s;i++)
            cout << " " ;
        cout << "|";
    }else if (n == 3){
		for(int i=0;i<s+2;i++)
            cout << " ";
    }
}
void DET(int n, int s, int ss) {
	if (n == 0)
		r0(s,ss);
	if (n == 1)
		r1(s, ss);
	if (n == 2)
		r2(s, ss);
	if (n == 3)
		r3(s, ss);
	if (n == 4)
		r4(s,ss);
	if (n == 5)
		r5(s,ss);
	if (n == 6)
		r6(s,ss);
	if (n == 7)
		r7(s,ss);
	if (n == 8)
		r8(s,ss);
	if (n == 9)
		r9(s,ss);

}
int main() {
#ifndef ONLINE_JUDGE
        freopen("test.in", "rt", stdin);
        freopen("out.txt", "wt", stdout);
#endif

	int n;
	while (true) {
		string d;
		cin >> n >> d;
		if (n == 0 && d == "0")
			break;
		for (int i = 0; i < d.size(); i++) {
			DET(int(d[i]) - '0', 1, n);
			if(i!=d.size()-1)
                cout << " ";
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			for (int i = 0; i < d.size(); i++) {
				DET(int(d[i]) - '0', 2, n);
				if(i!=d.size()-1)
                cout << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < d.size(); i++) {
			DET(int(d[i]) - '0', 3, n);
			if(i!=d.size()-1)
                cout << " ";
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			for (int i = 0; i < d.size(); i++) {
				DET(int(d[i]) - '0', 4, n);
				if(i!=d.size()-1)
                cout << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < d.size(); i++) {
			DET(int(d[i]) - '0', 5, n);
			if(i!=d.size()-1)
                cout << " ";
		}
		cout << endl;
		cout << endl;
	}
	return 0;
}
