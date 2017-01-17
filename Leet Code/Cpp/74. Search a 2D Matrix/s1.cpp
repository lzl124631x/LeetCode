class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int M = matrix.size(), N = matrix[0].size();
        int L = 0, R = M - 1;
        while (L <= R) {
            int MID = (L + R) / 2;
            if (matrix[MID][0] > target) R = MID - 1;
            else L = MID + 1;
        }
        --L;
        if (L < 0) return false;
        vector<int> &row = matrix[L];
        L = 0, R = N - 1;
        while (L <= R) {
            int MID = (L + R) / 2;
            if (row[MID] >= target) R = MID - 1;
            else L = MID + 1;
        }
        return L >= 0 && L < N && row[L] == target;
    }
};