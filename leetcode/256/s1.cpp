// OJ: https://leetcode.com/problems/paint-house/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        for (int i = 1; i < costs.size(); ++i) {
            for (int j = 0; j < 3; ++j) costs[i][j] += min(costs[i - 1][(j + 1) % 3], costs[i - 1][(j + 2) % 3]);
        }
        return *min_element(costs.back().begin(), costs.back().end());
    }
};