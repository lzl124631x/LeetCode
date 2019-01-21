// OJ: https://leetcode.com/problems/unique-paths/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long a = 1;
        for (int i = 1; i <= n - 1; ++i)
            a = a * (m - 1 + i) / i;
        return a;
    }
};