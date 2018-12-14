// OJ: https://leetcode.com/problems/min-cost-climbing-stairs/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev = 0, cur = 0;
        for (int i = 2; i <= cost.size(); ++i) {
            int newCur = min(cur + cost[i - 1], prev + cost[i - 2]);
            prev = cur;
            cur = newCur;
        }
        return cur;
    }
};