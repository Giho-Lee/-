/*
题目：https://www.nowcoder.com/practice/05182d328eb848dda7fdd5e029a56da9
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int len = 0;
	string str;
	while (cin >> str) {
	    len = str.length();
	    int times[26] = {0};
	    int min_val = 20;
	    for (int i = 0; i < len; i++) {
	        if (++times[str[i] - 'a'] < min_val) {
	            min_val = times[str[i] - 'a'];
	        }
	    }
	    string tmp = "";
	    for (int i = 0; i < len; i++) {
	        if (min_val != times[str[i] - 'a']) {
	            tmp += str[i];
	        }
	    }
	    cout << tmp << endl;
	}
    
	return 0;
}