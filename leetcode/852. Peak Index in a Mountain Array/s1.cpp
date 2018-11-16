// OJ: https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int i = 1;
        while (i < A.size() && A[i] > A[i - 1]) ++i;
        return i - 1;
    }
};