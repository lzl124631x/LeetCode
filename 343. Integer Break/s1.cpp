class Solution {
private:
    int dp[59];
public:
    int integerBreak(int n) {
        for (int i = 0; i < 59; ++i) {
            dp[i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = i; j <= n; ++j) {
                dp[j] = max(dp[j], dp[j - i] * i);
            }
        }
        return dp[n];
    }
};

// O(n^2) solution... so bad!