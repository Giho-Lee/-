/*
题目：https://www.nowcoder.com/practice/03ba8aeeef73400ca7a37a5f3370fe68
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool is_brother(string a, string b) {
     return (a == b) ? 0 : (
         sort(a.begin(), a.end()),
         sort(b.begin(), b.end()),
         a == b);
}

int main(int argc, char **argv) {
    int k = 0;
    int id = -1;
    int brother_count = 0;
    string brother, target;
    int num;
    vector<string> vec;
    cin >> num;
    while (num--) {
        cin >> brother;
        vec.push_back(brother);
    }
    cin >> target >> k;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++) {
        if (is_brother(vec[i], target)) {
            if (++brother_count == k) {
                id = i;
            }
        }
    }
    cout << brother_count << endl; 
    if (id >= 0)
        cout << vec[id] << endl;
    
    return 0;
}