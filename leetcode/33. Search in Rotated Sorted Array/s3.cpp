// OJ: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int search(vector<int>& A, int target) {
        if (A.empty()) return -1;
        int L = 0, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] == target) return M;
            if (A[M] > A[R]) {
                if (target > A[M]) L = M + 1;
                else if (target >= A[L]) R = M - 1;
                else L = M + 1;
            } else {
                if (target > A[M]) {
                    if (target <= A[R]) L = M + 1;
                    else R = M - 1;
                } else R = M - 1;
            }
        }
        return -1;
    }
};