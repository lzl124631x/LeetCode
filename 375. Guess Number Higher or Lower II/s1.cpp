class Solution {
private:
    int rec(vector<vector<int>> &dp, int i, int j) {
        if (i >= j) return 0;
        if (dp[i][j]) return dp[i][j];
        int minPay = INT_MAX;
        for (int k = i; k <= j; ++k) {
            int leftPay = rec(dp, i, k - 1), rightPay = rec(dp, k + 1, j);
            minPay = min(minPay, max(leftPay, rightPay) + k);
        }
        return dp[i][j] = minPay;
    }
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        return rec(dp, 1, n);
    }
};