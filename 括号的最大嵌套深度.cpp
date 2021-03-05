/*
题目：https://leetcode-cn.com/problems/maximum-nesting-depth-of-the-parentheses/
*/

class Solution {
public:
    int maxDepth(string s) {
        stack<char> stack_ch;
        int maxD = 0;
        int curD = 0;
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case '(': {
                    stack_ch.push(s[i]);
                    if (++curD > maxD) {
                        maxD = curD;
                    }
                    break;                  
                }
                case ')': {
                    stack_ch.pop();
                    curD--;
                    break;                  
                }
                default: {
                    break;
                }
            }
        }

        return maxD;
    }
};