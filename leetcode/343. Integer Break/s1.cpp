// OJ: https://leetcode.com/problems/integer-break/
// Author: github.com/lzl124631x
// Time: O(N * sqrt(N))
// Space: O(N)
class Solution {
public:
    int integerBreak(int n) {
        vector<int> memo(n + 1, 0);
        memo[1] = 1;
        for (int i = 2; i <= n; ++i) 
            for (int j = 1, b = ceil(sqrt(i)); j <= b; ++j)
                memo[i] = max(memo[i], max(j, memo[j]) * max(i - j, memo[i - j]));
        return memo[n];
    }
};