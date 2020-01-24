// OJ: https://leetcode.com/problems/minimum-falling-path-sum-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
    pair<int, int> getSmallestTwo(vector<int> &A) {
        auto p = make_pair(-1, -1);
        for (int i = 0; i < A.size(); ++i) {
            if (p.first == -1 || A[i] < A[p.first]) {
                p.second = p.first;
                p.first = i;
            } else if (p.second == -1 || A[i] < A[p.second]) p.second = i;
        }
        return p;
    }
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int N = A.size();
        if (N == 1) return A[0][0];
        for (int i = 1; i < N; ++i) {
            auto p = getSmallestTwo(A[i - 1]);
            for (int j = 0; j < N; ++j) {
                A[i][j] += A[i - 1][p.first == j ? p.second : p.first];
            }
        }
        return *min_element(A.back().begin(), A.back().end());
    }
};