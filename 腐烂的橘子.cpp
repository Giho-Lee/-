/*
题目：https://leetcode-cn.com/problems/rotting-oranges/
*/

class Solution {
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int M = grid.size(); // 行数
        int N = grid[0].size(); // 列数
        int freshNum = 0;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (2 == grid[i][j]) {
                    q.push({i, j});
                } else if (1 == grid[i][j]) {
                    freshNum++;
                }
            }
        }

        int round = 0;
        while (freshNum > 0 && !q.empty()) { // 无新鲜/腐烂则结束
            round++;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                pair<int, int> tmp = q.front();
                q.pop();
                int r = tmp.first;
                int c = tmp.second;
                if (r - 1 >= 0 && 1 == grid[r-1][c]) {
                    freshNum--;
                    grid[r-1][c] = 2;
                    q.push({r-1, c});
                }
                if (r + 1 < M && 1 == grid[r+1][c]) {
                    freshNum--;
                    grid[r+1][c] = 2;
                    q.push({r+1, c});
                }
                if (c - 1 >= 0 && 1 == grid[r][c-1]) {
                    freshNum--;
                    grid[r][c-1] = 2;
                    q.push({r, c-1});
                }
                if (c + 1 < N && 1 == grid[r][c+1]) {
                    freshNum--;
                    grid[r][c+1] = 2;
                    q.push({r, c+1});
                }
            }
        }

        return (freshNum > 0) ? -1 : round;
    }
};