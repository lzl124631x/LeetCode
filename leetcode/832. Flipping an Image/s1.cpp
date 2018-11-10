// OJ: https://leetcode.com/problems/flipping-an-image/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return {};
        int M = A.size(), N = A[0].size();
        vector<vector<int>> v(M, vector<int>(N));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                v[i][N - j - 1] = 1 - A[i][j];
            }
        }
        return v;
    }
};