/*
题目：https://leetcode-cn.com/problems/combinations/
*/

class Solution {
    vector<vector<int>> result;
    vector<int> path;
public:
    vector<vector<int>> combine(int n, int k) {
        result.clear();
        path.clear();

        dfs(n, k, 1);

        return result;
    }

    void dfs (int n, int k, int start_idx) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        for (int i = start_idx; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            dfs(n, k, i + 1);
            path.pop_back();
        }
    }
};