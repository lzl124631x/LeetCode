// OJ: https://leetcode.com/problems/split-array-largest-sum/
// Author: github.com/lzl124631x
// Time: O(N^2 * M)
// Space: O(N)
class Solution {
    typedef long long LL;
public:
    int splitArray(vector<int>& A, int M) {
        int N = A.size();
        vector<LL> dp(N, INT_MAX);
        LL s = 0;
        for (int i = 0; i < N; ++i) dp[i] = (s += A[i]);
        for (int m = 2; m <= M; ++m) {
            for (int i = N - 1; i >= m - 1; --i) {
                LL sum = 0;
                dp[i] = INT_MAX;
                for (int j = i; j >= m - 1; --j) {
                    sum += A[j];
                    dp[i] = min(dp[i], max(dp[j - 1], sum));
                }
            }
        }
        return dp[N - 1];
    }
};