/*
题目：https://leetcode-cn.com/problems/maximum-units-on-a-truck
*/

class Solution {
    static bool cmp(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int unitMax = 0;
        for (auto &it : boxTypes) {
            unitMax += min(it[0], truckSize) * it[1];
            truckSize -= it[0];
            if (truckSize <= 0) {
                break;
            }
        }
        return unitMax;
    }
};