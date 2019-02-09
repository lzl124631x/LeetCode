// OJ: https://leetcode.com/problems/squares-of-a-sorted-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i = 0, j = A.size() - 1, k = j;
        vector<int> ans(A.size());
        for (; i <= j; --k) {
            if (pow(A[i], 2) > pow(A[j], 2)) ans[k] = pow(A[i++], 2);
            else ans[k] = pow(A[j--], 2);
        }
        return ans;
    }
};