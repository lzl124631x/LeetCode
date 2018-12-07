// OJ: https://leetcode.com/problems/monotonic-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() <= 2) return true;
        int type = 0;
        for (int i = 1; i < A.size(); ++i) {
            int d = A[i] - A[i - 1];
            if (!d) continue;
            if (d > 0) {
                if (type == -1) return false;
                type = 1;
            } else {
                if (type == 1) return false;
                type = -1;
            }
        }
        return true;
    }
};