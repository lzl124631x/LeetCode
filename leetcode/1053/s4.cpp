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
        auto j = lower_bound(A.begin() + i + 1, A.end(), A[i]) - 1;
        auto k = lower_bound(A.begin() + i + 1, j, *j);
        swap(A[i], *k);
        return A;
    }
};