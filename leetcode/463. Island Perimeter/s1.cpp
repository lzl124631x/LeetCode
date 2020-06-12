// OJ: https://leetcode.com/problems/island-perimeter/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 0) continue;
                if (j + 1 >= N || A[i][j + 1] == 0) ++ans;
                if (j - 1 < 0 || A[i][j - 1] == 0) ++ans;
                if (i + 1 >= M || A[i + 1][j] == 0) ++ans;
                if (i - 1 < 0 || A[i - 1][j] == 0) ++ans;
            }
        }
        return ans;
    }
};