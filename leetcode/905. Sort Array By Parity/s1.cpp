// OJ: https://leetcode.com/problems/sort-array-by-parity/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        for (int i = 0, j = A.size() - 1; i < j; ++i, --j) {
            while (i < j && A[i] % 2 == 0) ++i;
            while (i < j && A[j] % 2 != 0) --j;
            if (i < j) swap(A[i], A[j]);
        }
        return A;
    }
};