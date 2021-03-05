/*
题目：https://www.nowcoder.com/practice/119bcca3befb405fbe58abe9c532eb29
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	string str;
	cin >> str;
	vector<string> vec;
	int x, y;
	x = y = 0;
	stringstream ss(str);
	while (ss.good()) {
	    string substr;
	    getline(ss, substr, ';');
	    vec.push_back(substr);
	}
	size_t len = 0;
	int v = 0;
	for (int i = 0; i < vec.size(); i++) {
	    v = 0;
	    string substr = vec.at(i);
	    len = substr.length();
	    if (0 == len || 1 == len || len > 3) 
	        continue;
	    if (2 == len && '0' <= substr[1] && substr[1] <= '9') {
	        v = substr[1] - '0';
	    } else if (3 == len && '0' <= substr[1] && substr[1] <= '9' && '0' <= substr[2] && substr[2] <= '9') {
	        v = (substr[1] - '0') * 10 + (substr[2] - '0');
	    }
	    
	    if (v) { 
            switch (substr[0]) {
                case 'A': {
                    x -= v;
                    break;
                }
                case 'D': {
                    x += v;
                    break;
                }
                case 'W': {
                    y += v;
                    break;
                }
                case 'S': {
                    y -= v;
                    break;
                }
                default: {
                    break;
                }
            }
	    }
	}
	
	cout << x << "," << y << endl;
	
	return 0;
}