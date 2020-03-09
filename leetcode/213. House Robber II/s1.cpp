// OJ: https://leetcode.com/problems/house-robber-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int rob(vector<int>& A, int start, int end) {
        if (start == end) return 0;
        if (start + 1 == end) return A[start];
        int prev2 = 0, prev = 0;
        for (int i = start; i < end; ++i) {
            int cur = max(prev, A[i] + prev2);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
public:
    int rob(vector<int>& A) {
        if (A.size() == 1) return A[0];
        return max(rob(A, 1, A.size()), rob(A, 0, A.size() - 1));
    }
};