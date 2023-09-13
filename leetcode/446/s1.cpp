// OJ: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
// Ref: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/solution/
class Solution {
    typedef long long LL;
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int N = A.size(), ans = 0;
        vector<unordered_map<LL, int>> dp(N);
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                LL d = (LL)A[i] - A[j];
                int sum = dp[j].count(d) ? dp[j][d] : 0;
                dp[i][d] += sum + 1;
                ans += sum;
            }
        }
        return ans;
    }
};