class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size() + 1, 0);
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') continue;
            int start = i - dp[i] - 1;
            if (start >= 0 && s[start] == '(')
                dp[i + 1] = dp[i] + 2 + dp[start];
            ans = max(ans, dp[i + 1]);
        }
        return ans;
    }
};