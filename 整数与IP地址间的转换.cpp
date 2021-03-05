/*
题目：https://www.nowcoder.com/practice/66ca0e28f90c42a196afd78cc9c496ea
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int len = 0;
	string str;
	while (cin >> str) {
	    if (string::npos != str.find(".")) {
	        unsigned int ip = 0;
	        unsigned char tmp = 0;
	        int shirt = 24;
	        len = str.length();
	        for (int i = 0; i < len; i++) {
	            if ('.' == str[i]) {
	                ip |= (tmp << shirt);
	                shirt -= 8;
	                tmp = 0;
	            } else {
	                tmp = tmp * 10 + (str[i] - '0');
	            }
	        }
	        ip |= (tmp << shirt) & 0xFF;
	        cout << ip << endl;
	    } else {
	        unsigned ip_int = stoul(str);
	        cout << ((ip_int >> 24) & 0xFF) << "." << ((ip_int >> 16) & 0xFF) << "." << ((ip_int >> 8) & 0xFF) << "." << (ip_int & 0xFF) << endl;
	    }
	}
	
	return 0;
}