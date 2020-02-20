// OJ: https://leetcode.com/problems/maximal-square/
// Author: github.com/lzl124631x
// Time: O((MN)^2)
// Space: O(1)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int M = A.size(), N = A[0].size(), ans = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int k = 0;
                bool stop = false;
                for (; i + k < M && j + k < N; ++k) {
                    for (int t = 0; t < k + 1 && !stop; ++t) {
                        if (A[i + t][j + k] == '0') stop = true;
                    }
                    for (int t = 0; t < k + 1 && !stop; ++t) {
                        if (A[i + k][j + t] == '0') stop = true;
                    }
                    if (stop) break;
                }
                ans = max(ans, k);
            }
        }
        return ans * ans;
    }
};