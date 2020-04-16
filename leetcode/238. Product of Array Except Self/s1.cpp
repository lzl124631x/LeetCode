// OJ: https://leetcode.com/problems/product-of-array-except-self/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& A) {
        int N = A.size(), prod = 1;
        vector<int> ans(A.begin(), A.end());
        for (int i = N - 2; i >= 0; --i) ans[i] *= ans[i + 1];
        for (int i = 0; i < N; ++i) {
            ans[i] = prod * (i + 1 >= N ? 1 : ans[i + 1]);
            prod *= A[i];
        }
        return ans;
    }
};