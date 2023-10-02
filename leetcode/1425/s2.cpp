// OJ: https://leetcode.com/problems/constrained-subsequence-sum/
// Author: github.com/lzl124631x
// Time: O(NlogK)
// Space: O(N)
class Solution {
public:
    int constrainedSubsetSum(vector<int>& A, int k) {
        int maxVal = *max_element(begin(A), end(A));
        if (maxVal <= 0) return maxVal;
        int N = A.size(), ans = 0;
        multiset<int> s{0};
        vector<int> dp(N);
        for (int i = 0; i < N; ++i) {
            int sum = (s.size() ? *s.rbegin() : 0) + A[i];
            if (i >= k) s.erase(s.find(dp[i - k]));
            s.insert(sum);
            dp[i] = sum;
            ans = max(ans, sum);
        }
        return ans;
    }
};