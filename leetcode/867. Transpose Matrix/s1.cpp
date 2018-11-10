// OJ: https://leetcode.com/problems/transpose-matrix/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return {};
        int M = A.size(), N = A[0].size();
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                v[j][i] = A[i][j];
            }
        }
        return v;
    }
};