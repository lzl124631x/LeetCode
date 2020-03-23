// OJ: https://leetcode.com/problems/interleaving-string/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    bool isInterleave(string a, string b, string c) {
        int M = a.size(), N = b.size();
        if (M + N != c.size()) return false;
        vector<int> dp(N + 1);
        for (int i = M; i >= 0; --i) {
            for (int j = N; j >= 0; --j) {
                if (i == M && j == N) dp[j] = true;
                else dp[j] = (i < M && a[i] == c[i + j] && dp[j])
                    || (j < N && b[j] == c[i + j] && dp[j + 1]);
            }
        }
        return dp[0];
    }
};