// OJ: https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target
// Author: github.com/lzl124631x
// Time: O(T)
// Space: O(T)
class Solution {
    inline bool isGreaterThan(string &a, string &b) {
        return a.size() != b.size() ? a.size() > b.size() : a > b;
    }
public:
    string largestNumber(vector<int>& A, int T) {
        int N = A.size();
        vector<string> dp(T + 1, "0");
        dp[0] = "";
        for (int i = 0; i < N; ++i) {
            for (int c = 1; c <= T; ++c) {
                if (c < A[i] || dp[c - A[i]] == "0") continue;
                auto s = string(1, '1' + i) + dp[c - A[i]];
                if (isGreaterThan(s, dp[c])) dp[c] = s;
            }
        }
        return dp[T];
    }
};