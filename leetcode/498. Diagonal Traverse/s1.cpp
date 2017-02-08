class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        vector<int> ans;
        int M = matrix.size(), N = matrix[0].size(), end = M * N;
        bool topRight = true;
        for (int i = 0, j = 0, c = 0; c < end; ++c) {
            ans.push_back(matrix[i][j]);
            if (topRight) {
                if (j == N - 1) ++i, topRight = !topRight;
                else if (i == 0) ++j, topRight = !topRight;
                else --i, ++j;
            } else {
                if (i == M - 1) ++j, topRight = !topRight;
                else if (j == 0) ++i, topRight = !topRight;
                else ++i, --j;
            }
        }
        return ans;
    }
};