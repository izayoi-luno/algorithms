// leetcode #64  最小路径和
// 矩阵 - 二维dp

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else if(i == 0) dp[i][j] = dp[i][j - 1] + grid[i][j];
                else if(j == 0) dp[i][j] = dp[i - 1][j] + grid[i][j];
                else dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n - 1][m - 1];
    }
};