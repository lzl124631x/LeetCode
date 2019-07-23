// OJ: https://leetcode.com/problems/stone-game/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int N = piles.size();
        vector<vector<int>> memo(N);
        for (int i = 0; i < N; ++i) memo[i] = vector<int>{ piles[i], 0 };
        for (int len = 2; len <= N; ++len) {
            for (int i = 0; i <= N - len; ++i) {
                auto a = vector<int>{ memo[i + 1][1] + piles[i], memo[i + 1][0] };
                auto b = vector<int>{ memo[i][1] + piles[i + len - 1], memo[i][0] };
                memo[i] = a[0] - a[1] > b[0] - b[1] ? a : b;
            }
        }
        return memo[0][0] > memo[0][1];
    }
};