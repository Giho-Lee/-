/*
题目：https://www.nowcoder.com/practice/8e400fd9905747e4acc2aeed7240978b
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool cmp0(pair<string, int> a, pair<string, int> b) {
    return a.second < b.second;
}

bool cmp1(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

int main(int argc, char **argv) {
    int num;
    int order;
    while (cin >> num >> order) {
        string name;
        uint score;
        vector<pair<string, int>> vec;
        while (num--) {
            cin >> name >> score;
            vec.push_back(make_pair(name, score));
        }
        if (order) {
            stable_sort(vec.begin(), vec.end(), cmp0);
        } else {
            stable_sort(vec.begin(), vec.end(), cmp1);
        }

        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i].first << " " << vec[i].second << endl;
        }
    }
    
    return 0;
}