/*
题目：https://www.nowcoder.com/practice/cc57022cb4194697ac30bcb566aeb47b
*/

#include <iostream>
#include <string>
#include <bits/stdc++.h> // reverse need
using namespace std;

int main() {
    string str;
    getline(cin, str);
    reverse(str.begin(), str.end());     
    cout << str << endl;
    
	return 0;
}