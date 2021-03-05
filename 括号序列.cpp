/*
题目：https://www.nowcoder.com/practice/37548e94a270412c8b9fb85643c8ccc2
*/

class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s) {
        // write code here
        stack<char> stack_ch;
        for (int i = 0; i < s.length(); i++) {
            if (stack_ch.empty()) {
                stack_ch.push(s[i]);
                continue;
            }
            char top = stack_ch.top();
            if ( (')' == s[i] && '(' == top) 
                || ('}' == s[i] && '{' == top) 
                || (']' == s[i] && '[' == top) ) {
                stack_ch.pop();
            } else {
                stack_ch.push(s[i]);
            }
        }
        
        return  stack_ch.empty();
    }
};