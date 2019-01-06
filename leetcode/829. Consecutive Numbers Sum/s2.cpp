// OJ: https://leetcode.com/problems/consecutive-numbers-sum/
// Author: github.com/lzl124631x
// Time: O(sqrt(N))
// Space: O(1)
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans = 0, n = 1, s = 1;
        for (; s <= N; s += ++n) {
            if ((N - s + n) % n == 0) ++ans;
        }
        return ans;
    }
};