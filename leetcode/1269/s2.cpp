// OJ: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
// Author: github.com/lzl124631x
// Time: O(S * min(S, L))
// Space: O(min(S, L))
// Ref: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/discuss/436392/C%2B%2B-Bottom-Up-DP
class Solution {
public:
    int numWays(int steps, int arrLen) {
        int N = min(steps / 2 + 1, arrLen);
        vector<int> a(N + 2), b(N + 2);
        a[1] = 1;
        while (steps--) {
            for (int i = 1; i <= N; ++i) b[i] = ((long)a[i - 1] + a[i] + a[i + 1]) % ((int)1e9+7);
            swap(a, b);
        }
        return a[1];
    }
};