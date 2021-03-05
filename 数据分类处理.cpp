/*
题目：https://www.nowcoder.com/practice/9a763ed59c7243bd8ab706b2da52b7fd
*/

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
    vector<uint> I, R, result;
    int num_I, num_R;
    uint data;
    int i;
    while (cin >> num_I) {
        result.clear();
        I.clear();
        R.clear();
        
        for (i = 0; i < num_I; i++) {
            cin >> data;
            I.push_back(data);
        }
        cin >> num_R;
        for (i = 0; i < num_R; i++) {
            cin >> data;
            R.push_back(data);
        }
        sort(R.begin(), R.end());
        R.erase(unique(R.begin(), R.end()), R.end());
        for (i = 0; i < R.size(); i++) {
            int first = 1;
            int count_idx = 0;
            int count = 0;
            for (int j = 0; j < num_I; j++) {
                if (string::npos != to_string(I[j]).find(to_string(R[i]))) {
                    if (first) {
                        first = 0;
                        result.push_back(R[i]);
                        count_idx = result.size();
                        result.push_back(0);
                    }
                    count++;
                    result.push_back(j);
                    result.push_back(I[j]);
                }
            }
            if (count > 0)
                result[count_idx] = count;
        }

        if (!result.empty()) {
            cout << result.size() << " ";
            for (i = 0; i < result.size() - 1; i++) {
                cout << result[i] << " ";
            }
            cout << result[i] << endl;
        }
    }
    
    return 0;
}