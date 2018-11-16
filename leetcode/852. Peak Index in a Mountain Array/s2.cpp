// OJ: https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int L = 1, R = A.size() - 2;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] > A[M - 1]) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};