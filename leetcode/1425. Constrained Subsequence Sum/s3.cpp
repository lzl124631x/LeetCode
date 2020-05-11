// OJ: https://leetcode.com/problems/constrained-subsequence-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int constrainedSubsetSum(vector<int>& A, int k) {
        int maxVal = *max_element(begin(A), end(A));
        if (maxVal <= 0) return maxVal;
        int N = A.size(), ans = 0;
        deque<int> mx;
        vector<int> dp(N);
        for (int i = 0; i < N; ++i) {
            if (mx.size() && mx.front() == i - k - 1) mx.pop_front();
            dp[i] = max(0, mx.size() ? dp[mx.front()] : 0) + A[i];
            while (mx.size() && dp[mx.back()] <= dp[i]) mx.pop_back();
            mx.push_back(i);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};