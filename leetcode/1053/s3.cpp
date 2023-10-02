// OJ: https://leetcode.com/problems/previous-permutation-with-one-swap/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int i = A.size() - 2;
        while (i >= 0 && A[i] <= A[i + 1]) --i;
        if (i < 0) return A;
        int j = i + 1;
        for (int k = i + 2; k < A.size() && A[k] < A[i]; ++k) {
            if (A[k] > A[j]) j = k;
        }
        swap(A[i], A[j]);
        return A;
    }
};