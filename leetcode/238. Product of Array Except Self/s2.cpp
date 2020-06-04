// OJ: https://leetcode.com/problems/product-of-array-except-self/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& A) {
        int N = A.size(), left = 1, right = 1;
        vector<int> ans(N, 1);
        for (int i = 0, j = N - 1; i < N; ++i, --j) {
            ans[i] *= left;
            left *= A[i];
            ans[j] *= right;
            right *= A[j];
        }
        return ans;
    }
};