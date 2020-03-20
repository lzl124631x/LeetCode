// OJ: https://leetcode.com/problems/maximum-product-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& A) {
        int ans = A[0], N = A.size(), j = 0;
        while (j < N) {
            int prod = 1;
            int i = j;
            while (j < N && A[j] != 0) {
                prod *= A[j++];
                ans = max(ans, prod);
            }
            if (j < N) ans = max(ans, 0);
            while (i < N && prod < 0) {
                prod /= A[i++];
                if (i != j) ans = max(ans, prod);
            }
            while (j < N && A[j] == 0) ++j;
        }
        return ans;
    }
};