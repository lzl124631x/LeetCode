// OJ: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// Author: github.com/lzl124631x
// Time: O(K)
// Space: O(1)
class Solution {
public:
    int maxScore(vector<int>& A, int k) {
        int ans = 0, N = A.size(), left = 0, right = 0;
        for (int i = 0; i < k; ++i) right += A[N - i - 1];
        ans = right;
        for (int i = 0; i < k; ++i) {
            left += A[i];
            right -= A[N - k + i];
            ans = max(ans, left + right);
        }
        return ans;
    }
};