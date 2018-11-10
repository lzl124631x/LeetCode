// OJ: https://leetcode.com/problems/flipping-an-image/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return {};
        int M = A.size(), N = A[0].size();
        for (int i = 0; i < M; ++i) {
            int L = 0, R = N - 1;
            while (L < R) swap(A[i][L++], A[i][R--]);
        }
        for (auto &row: A) {
            for (auto &n: row) {
                n = 1 - n;
            }
        }
        return A;
    }
};