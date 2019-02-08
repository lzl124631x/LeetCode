// OJ: https://leetcode.com/problems/one-edit-distance/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M,N))
class Solution {
private:
    int editDistance(string &s, string &t) {
        if (s.size() < t.size()) swap(s, t);
        int M = s.size(), N = t.size();
        vector<int> dp(N + 1, 0);
        for (int i = 1; i <= N; ++i) dp[i] = i;
        for (int i = 1; i <= M; ++i) {
            int pre = dp[0];
            dp[0] = i;
            for (int j = 1; j <= N; ++j) {
                int tmp = dp[j];
                if (s[i - 1] == t[j - 1]) dp[j] = pre;
                else dp[j] = min(pre, min(dp[j - 1], dp[j])) + 1;
                pre = tmp;
            }
        }
        return dp[N];
    }
public:
    bool isOneEditDistance(string s, string t) {
        return editDistance(s, t) == 1;
    }
};