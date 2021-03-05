/*
题目：https://www.nowcoder.com/practice/b4525d1d84934cf280439aeecc36f4af
*/


class Solution {
public:
    int getLongestPalindrome(string A, int n) {
        // write code here
        int r = 0;
        int l = 0;
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {          
            //奇数为中心
            r = i;
            l = i;   
            while (l >= 0 && r < n && A[l] == A[r]) { 
                --l;
                ++r;
            }
            maxLen = max(maxLen, r - l - 1);
            
            //偶数为中心
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && A[l] == A[r]) { 
                --l;
                ++r;
            }
            maxLen = max(maxLen, r - l - 1); 
        }
        
        return maxLen;
    }
};