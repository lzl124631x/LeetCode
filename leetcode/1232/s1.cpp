// OJ: https://leetcode.com/problems/check-if-it-is-a-straight-line/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& A) {
        int N = A.size(), x1 = A[0][0], y1 = A[0][1], x2 = A[1][0], y2 = A[1][1];
        for (int i = 2; i < N; ++i) {
            if ((A[i][1] - y1) * (x2 - x1) != (y2 - y1) * (A[i][0] - x1)) return false;
        }
        return true;
    }
};