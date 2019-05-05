// OJ: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^2)
// Ref: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/discuss/286753/C%2B%2B-with-picture
class Solution {
private:
    int dp[50][50] = {0};
    int minScoreTriangulation(vector<int>& A, int i, int j) {
        if (j - i < 2) return 0;
        if (dp[i][j]) return dp[i][j];
        int ans = INT_MAX;
        for (int k = i + 1; k < j; ++k) {
            ans = min(ans, minScoreTriangulation(A, i, k) + A[i] * A[j] * A[k] + minScoreTriangulation(A, k, j));
        }
        return dp[i][j] = ans;
    }
public:
    int minScoreTriangulation(vector<int>& A) {
        return minScoreTriangulation(A, 0, A.size() - 1);
    }
};