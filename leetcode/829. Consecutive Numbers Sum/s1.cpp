// OJ: https://leetcode.com/problems/consecutive-numbers-sum/
// Author: github.com/lzl124631x
// Time: O(sqrt(N))
// Space: O(1)
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans = 0;
        for (int n = 1; n <= N && n * (n - 1) < 2 * N; ++n) {
            int a = (2 * N - n * (n - 1)), b = 2 * n;
            if (a % b) continue;
            int s = a / b;
            if (s >= 1 && s + n - 1 <= N) ++ans;
        }
        return ans;
    }
};