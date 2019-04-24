// OJ: https://leetcode.com/problems/coin-change-2/
// Author: github.com/lzl124631x
// Time: O(A * C^2)
// Space: O(AC)
class Solution {
private:
    unordered_map<int, int> memo;
    int change(int amount, vector<int>& coins, int start) {
        if (!amount) return 1;
        if (start >= coins.size()) return 0;
        int key = amount * 1000 + start;
        if (memo.find(key) != memo.end()) return memo[key];
        int ans = 0;
        for (int i = start; i < coins.size(); ++i) {
            if (amount >= coins[i]) ans += change(amount - coins[i], coins, i);
        }
        return memo[key] = ans;
    }
public:
    int change(int amount, vector<int>& coins) {
        return change(amount, coins, 0);
    }
};