class Solution {
public:
    int numDistinct(string s, string t) {
        int M = s.size(), N = t.size();
        vector<int> dp(N + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= M; ++i) {
            for (int j = N; j >= 0; --j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[N];
    }
};