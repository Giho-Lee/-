/*
题目：https://www.nowcoder.com/practice/f9a4c19050fc477e9e27eb75f3bfd49c
*/

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main (int argc, char **argv) {
    int n;
    int maxWeight = 0;
    while (cin >> n) {
        vector<int> weights(n), nums(n);
        for (int i = 0; i < n; i++) {
            cin >> weights[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            maxWeight += nums[i] * weights[i];
        }

        set<int> s;
        s.insert(maxWeight);

        for (int i = 0; i < n; i++) {
            set<int>::iterator iter = s.begin();
            while (iter != s.end()) {
                for (int j = 1; j <= nums[i]; j++) {
                    int tmp = *iter - j * weights[i];  // 减去相应的数量砝码
                    if (tmp < 0) { 
                        break;
                    }
                    // 若重量还是大于等于0，则插入
                    s.insert(tmp);
                }
                iter++;
            }
        }
        cout << s.size() << endl;
    }
    
    return 0;
}