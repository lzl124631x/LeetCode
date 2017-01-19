// https://discuss.leetcode.com/topic/3227/don-t-treat-it-as-a-2d-matrix-just-treat-it-as-a-sorted-list
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int M = matrix.size(), N = matrix[0].size();
        int L = 0, R = M * N - 1;
        while (L <= R) {
            int MID = (L + R) / 2;
            if (matrix[MID / N][MID % N] >= target) R = MID - 1;
            else L = MID + 1;
        }
        return L >= 0 && L <= M * N - 1 && matrix[L / N][L % N] == target;
    }
};