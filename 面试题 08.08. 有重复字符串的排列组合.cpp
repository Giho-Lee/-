/*
题目：https://leetcode-cn.com/problems/permutation-ii-lcci/
*/

class Solution {
    vector<string> result;
public:
    vector<string> permutation(string S) {
        sort(S.begin(), S.end());
        vector<bool> visited(S.size(), false);
        string path = "";
        dfs(0, visited, S, path);

        return result;   
    }

    void dfs(int n, vector<bool> &visited, string s, string &path) {
        if (visited.size() == n) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            if (visited[i])
                continue;
            if (i > 0 && s[i] == s[i-1] && !visited[i-1])
                continue;
            visited[i] = true;
            path.push_back(s[i]); //处理节点
            dfs(n+1, visited, s, path);
            path.pop_back(); //回溯，撤销处理的节点
            visited[i] = false; 
        }
    }
};