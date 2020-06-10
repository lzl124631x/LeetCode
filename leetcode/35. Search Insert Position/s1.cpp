// OJ: https://leetcode.com/problems/search-insert-position/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int searchInsert(vector<int>& A, int target) {
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return M;
            if (A[M] < target) L = M + 1;
            else R = M - 1;
        }
        return L;
    }
};