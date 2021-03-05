/*
题目：https://www.nowcoder.com/practice/5af18ba2eb45443aa91a11e848aa6723
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main (int argc, char **argv) {
    int rows;
    cin >> rows;
    string s;
    vector<string> vec;
    for (int i = 0; i < rows; i++) {
        cin >> s;
        vec.push_back(s);
    }
    sort(vec.begin(), vec.end());
    vector<string>::iterator it;
    for (it = vec.begin(); it != vec.end(); it++) {
        cout << it->data() << endl;
    }
    return 0;
}