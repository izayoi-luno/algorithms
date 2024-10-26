// leetcode #3102. 最小化曼哈顿距离
// 枚举

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        multiset<int> sx, sy;
        for (auto & p : points) {
            sx.emplace(p[0] - p[1]);
            sy.emplace(p[0] + p[1]);
        }
        int res = INT_MAX;
        for (auto &p : points) {
            sx.erase(sx.find(p[0] - p[1]));
            sy.erase(sy.find(p[0] + p[1]));
            res = min(res, max(*sx.rbegin() - *sx.begin(), *sy.rbegin() - *sy.begin()));
            sx.emplace(p[0] - p[1]);
            sy.emplace(p[0] + p[1]);
        }
        return res;
    }
};
