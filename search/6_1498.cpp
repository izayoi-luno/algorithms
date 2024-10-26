// leetcode #1498. 满足条件的子序列数目
// 二分查找 + O(nlogn)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static constexpr int P = int(1E9) + 7;
    static constexpr int MAX_N = int(1E5) + 5;

    int f[MAX_N];

    void pretreatment() {
        f[0] = 1;
        for (int i = 1; i < MAX_N; ++i) {
            f[i] = (long long)f[i - 1] * 2 % P;
        }
    }

    int numSubseq(vector<int>& nums, int target) {
        pretreatment();  // 预处理贡献，所谓的贡献就是可能取值的排列数量

        sort(nums.begin(), nums.end());

        int ans = 0;
        for (int i = 0; i < nums.size() && nums[i] * 2 <= target; ++i) {
            int maxValue = target - nums[i];
            int pos = upper_bound(nums.begin(), nums.end(), maxValue) - nums.begin() - 1;
            int contribute = (pos >= i) ? f[pos - i] : 0;  // 去掉重复值
            ans = (ans + contribute) % P;
        }

        return ans;
    }
};