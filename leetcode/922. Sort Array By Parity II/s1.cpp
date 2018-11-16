// OJ: https://leetcode.com/problems/sort-array-by-parity-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        for (int i = 0, j = 1, N = A.size(); i < N && j < N; i += 2, j += 2) {
            while (A[i] % 2 == 0) i += 2;
            while (A[j] % 2 != 0) j += 2;
            if (i < N) swap(A[i], A[j]);
        }
        return A;
    }
};