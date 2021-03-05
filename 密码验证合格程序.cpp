/*
题目：https://www.nowcoder.com/practice/184edec193864f0985ad2684fbc86841
*/

#include <iostream>
#include <string>

using namespace std;

bool check_fun1 (string &str, int len) {
    int count[4] = {0};
    int sum = 0;
    for (int i = 0; i < len; i++) {
        switch (str[i]) {
            case 'a'...'z': {
                count[0] = 1;
                break;
            }
            case 'A'...'Z': {
                count[1] = 1;
                break;
            }
            case '0'...'9': {
                count[2] = 1;
                break;
            }
            default: {
                count[3] = 1;
                break;
            }
        }
    }
    
    return  (count[0] + count[1] + count[2] + count[3]) > 2;
}

bool check_fun2 (string &str, int len) {
    for (int i = 0; i < len - 3; i++) {
        string substr = str.substr(i, 3);
        if (string::npos != str.find(substr, i + 1)) {
            return false;
        }
    }
    
    return true;
}

int main() {
	string str;
	int len = 0;
	while (cin >> str) {
	    len = str.length();
	    if (len <= 8 || !check_fun1(str, len) || !check_fun2(str, len)) {
	        cout << "NG" << endl;
	    } else {
	        cout << "OK" << endl;
	    }
	}
	
	
	return 0;
}