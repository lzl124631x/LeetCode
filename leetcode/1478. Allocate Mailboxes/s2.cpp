// OJ: https://leetcode.com/problems/allocate-mailboxes/
// Author: github.com/lzl124631x
// Time: O(N^2 * K)
// Space: O(N)
// Ref: https://leetcode.com/problems/allocate-mailboxes/discuss/685403/JavaC%2B%2BPython-DP-Solution
class Solution {
    int dist(vector<int> &presum, int i, int j) {
        return (presum[j + 1] - presum[(i + j + 1) / 2]) - (presum[(i + j) / 2 + 1] - presum[i]);
    }
public:
    int minDistance(vector<int>& A, int K) {
        if (A.size() == K) return 0;
        sort(begin(A), end(A));
        int N = A.size(); 
        vector<int> presum(N + 1);
        for (int i = 0; i < N; ++i) presum[i + 1] = presum[i] + A[i];
        vector<int> dp(N + 1, 1e6);
        for (int i = 0; i < N; ++i) dp[i + 1] = dist(presum, 0, i);
        for (int k = 2; k <= K; ++k) {
            for (int i = N - 1; i >= 0; --i) {
                for (int j = i; j >= k - 1; --j) {
                    dp[i + 1] = min(dp[i + 1], dp[j] + dist(presum, j, i));
                }
            }
        }
        return dp[N];
    }
};