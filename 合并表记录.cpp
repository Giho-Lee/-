/*
题目：https://www.nowcoder.com/practice/de044e89123f4a7482bd2b214a685201
*/

#include <iostream>
#include <map>
using namespace std;

int main (int argc, char **argv) {
    int rows;
    cin >> rows;
    map<int, int> m;
    for (int i = 0; i < rows; i++) {
        int index, value;
        cin >> index >> value;
        if (m.end() != m.find(index)) {
            m[index] += value;
        } else {
            m[index] = value;
        }
    }
    map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}