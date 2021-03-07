/*
题目：https://www.nowcoder.com/practice/c1f9561de1e240099bdb904765da9ad0
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b) {
    if (a.second != b.second)
        return (a.second > b.second);  // 降序
    return (a.first < b.first); // 升序
}

void my_sort(map<char, int> &m) {
    vector<pair<char, int>> vec;
    for (auto &it : m) {
        vec.push_back(it);
    }
    sort(vec.begin(), vec.end(), cmp);
     for (auto &it : vec) {
        cout << it.first;
    }
     cout << endl;
}

int main(int argc, char **argv) {
    string str;
    while (cin >> str) {
        map<char, int> m;
        int n = str.length();
        for (int i = 0; i < n; i++) {
            if (m.find(str[i]) != m.end()) {
                m[str[i]] += 1;
            } else {
                m[str[i]] = 1;
            }
        }        
        my_sort(m);
    }
    
    return 0;
}