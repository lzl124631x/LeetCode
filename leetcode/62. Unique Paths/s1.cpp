// OJ: https://leetcode.com/problems/unique-paths/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> memo(n + 1, 0);
        memo[n - 1] = 1;
        for (int i = m - 1; i >= 0; --i) 
            for (int j = n - 1; j >= 0; --j) 
                memo[j] += memo[j + 1];
        return memo[0];
    }
};