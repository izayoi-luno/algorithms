// leetcode #646 最长数对链
// 最长递增子序列

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, 1);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(pairs[j][1] < pairs[i][0]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        return dp[n - 1];
    }
};