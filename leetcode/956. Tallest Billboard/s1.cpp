// OJ: https://leetcode.com/problems/tallest-billboard
// Author: github.com/lzl124631x
// Time: O(NS) where N is the length of `rods`,
//             and S is the maximum of `sum(rods[i..j])`
// Space: O(NS)
// Ref: https://leetcode.com/articles/tallest-billboard/
class Solution {
private:
    vector<vector<int>> dp;
    int dfs(vector<int>& rods, int i, int s) {
        if (i == rods.size()) return s == 5000 ? 0 : INT_MIN;
        if (dp[i][s] != INT_MIN) return dp[i][s];
        int ans = dfs(rods, i + 1, s);
        ans = max(ans, dfs(rods, i + 1, s - rods[i]));
        ans = max(ans, rods[i] + dfs(rods, i + 1, s + rods[i]));
        return dp[i][s] = ans;
    }
public:
    int tallestBillboard(vector<int>& rods) {
        int N = rods.size();
        dp = vector<vector<int>>(N, vector<int>(10001, INT_MIN));
        return dfs(rods, 0, 5000);
    }
};