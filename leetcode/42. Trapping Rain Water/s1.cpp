// OJ: https://leetcode.com/problems/trapping-rain-water/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int trap(vector<int>& A) {
        if (A.empty()) return 0;
        int N = A.size(), ans = 0;
        vector<int> left(N, 0), right(N, 0);
        left[0] = A[0];
        right[N - 1] = A[N - 1];
        for (int i = 1; i < N; ++i) left[i] = max(left[i - 1], A[i]);
        for (int i = N - 2; i >= 0; --i) right[i] = max(right[i + 1], A[i]);
        for (int i = 1; i < N - 1; ++i) {
            ans += min(left[i], right[i]) - A[i];
        }
        return ans;
    }
};