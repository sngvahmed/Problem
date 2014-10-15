#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class SuperRot {
public:
	char Shift(char word, int shifting) {
		if (word <= 'Z' && word >= 'A') {
			int num = word;
			if (num + shifting > 'Z')
				word = 'A' + shifting;
			else if (num + shifting < 'A')
				word = 'Z' + shifting;
			else
				word = word + shifting;
		} else if (word >= 'a' && word <= 'z') {
			int num = word;
			if (num + shifting > 'z')
				word = 'a' + shifting;
			else if (num + shifting < 'a')
				word = 'z' + shifting;
			else
				word = word + shifting;
		}
		return word;
	}

	string decoder(string message) {
		for (int i = 0; i < message.size(); i++)
			if (message[i] != ' ') {
				if (message[i] <= 123 && message[i] >= 97 || message[i] <= 91
						&& message[i] >= 65)
					message[i] = Shift(message[i], 13);
				else {
					if (message[i] == '1')
						message[i] = '6';
					else if (message[i] == '2')
						message[i] = '7';
					else if (message[i] == '3')
						message[i] = '8';
					else if (message[i] == '4')
						message[i] = '9';
					else if (message[i] == '0')
						message[i] = '5';
					else if (message[i] == '5')
						message[i] = '0';
					else if (message[i] == '6')
						message[i] = '1';
					else if (message[i] == '7')
						message[i] = '2';
					else if (message[i] == '8')
						message[i] = '3';
					else if (message[i] == '9')
						message[i] = '4';
				}
			}
		return message;
	}

};
