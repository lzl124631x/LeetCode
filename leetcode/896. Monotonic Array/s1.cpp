// OJ: https://leetcode.com/problems/monotonic-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int dir = 0;
        for (int i = 1; i < A.size(); ++i) {
            int d = A[i] == A[i - 1] ? 0 : (A[i] > A[i - 1] ? 1 : -1);
            if (dir && d && dir != d) return false;
            if (d) dir = d;
        }
        return true;
    }
};