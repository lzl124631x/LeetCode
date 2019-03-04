// OJ: https://leetcode.com/problems/minimum-falling-path-sum/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int N = A.size();
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                A[i][j] += min(j - 1 >= 0 ? A[i - 1][j - 1] : INT_MAX,
                                   min(A[i - 1][j],
                                       j + 1 < N ? A[i - 1][j + 1] : INT_MAX));
            }
        }
        return *min_element(A.back().begin(), A.back().end());
    }
};