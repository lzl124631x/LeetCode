// OJ: https://leetcode.com/problems/maximal-square/
// Author: github.com/lzl124631x
// Time: O(MN^2)
// Space: O(MN)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<vector<int>> row(M, vector<int>(N, 0)), col(M, vector<int>(N, 0));
        for (int i = 0; i < M; ++i) {
            int start = -1;
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == '0') start = j;
                row[i][j] = j - start;
            }
        }
        for (int j = 0; j < N; ++j) {
            int start = -1;
            for (int i = 0; i < M; ++i) {
                if (A[i][j] == '0') start = i;
                col[i][j] = i - start;
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int end = min(row[i][j], col[i][j]), k = 0;
                while (k < end) {
                    ++k;
                    if (j - k < 0) break;
                    end = min(end, col[i][j - k]);
                }
                ans = max(ans, k);
            }
        }
        return ans * ans;
    }
};