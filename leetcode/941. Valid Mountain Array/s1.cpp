// OJ: https://leetcode.com/problems/valid-mountain-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int i = 1, N = A.size();
        for (; i < N && A[i] > A[i - 1]; ++i);
        if (i == 1 || i == N) return false;
        for (; i < N && A[i] < A[i - 1]; ++i);
        return i == N;
    }
};