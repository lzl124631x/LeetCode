// OJ: https://leetcode.com/problems/previous-permutation-with-one-swap/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int first = -1, second;
        for (int i = A.size() - 1; i > first; --i) {
            while (i - 1 > first && A[i - 1] == A[i]) --i;
            int j = i - 1;
            while (j > first && A[j] <= A[i]) --j;
            if (j > first) {
                first = j;
                second = i;
            }
        }
        if (first > -1) swap(A[first], A[second]);
        return A;
    }
};