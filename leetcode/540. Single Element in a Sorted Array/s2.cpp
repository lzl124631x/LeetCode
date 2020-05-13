// OJ: https://leetcode.com/problems/single-element-in-a-sorted-array/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int L = 0, R = A.size() - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if (M % 2) M--;
            if (A[M] == A[M + 1]) L = M + 2;
            else R = M;
        }
        return A[L];
    }
};