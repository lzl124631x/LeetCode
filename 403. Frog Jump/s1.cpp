class Solution {
private:
    bool rec(vector<int> &stones, vector<unordered_map<int, bool>> &dp, int start, int step) {
        if (start == stones.size() - 1) {
            return true;
        }
        if (dp[start].count(step)) return dp[start][step];
        dp[start][step] = false;
        int index = start + 1;
        for (int i = -1; i <= 1; ++i) {
            int target = stones[start] + step + i;
            while (index < stones.size() && stones[index] < target) ++index;
            if (stones[index] == target) {
                dp[start][step] = dp[start][step] || rec(stones, dp, index, step + i);
            }
        }
        return dp[start][step];
    }
public:
    bool canCross(vector<int>& stones) {
        if (stones.size() < 2 || stones[0] != 0 || stones[1] != 1) return false;
        vector<unordered_map<int, bool>> dp(stones.size());
        return rec(stones, dp, 1, 1);
    }
};