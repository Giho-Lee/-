/*
题目：https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxLen = 0;
        int n = nums.size();
        if (0 == n) {
            return maxLen;
        }
        int curMaxLen = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                curMaxLen++;
            } else {
                if (curMaxLen > maxLen) {
                    maxLen = curMaxLen;
                }
                curMaxLen = 1;    
            }
        }

        if (curMaxLen > maxLen) {
            maxLen = curMaxLen;
        }
        
        return maxLen;
    }
};