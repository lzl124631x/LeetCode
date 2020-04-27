// OJ: https://leetcode.com/problems/make-array-strictly-increasing/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
// Ref: https://leetcode.com/problems/make-array-strictly-increasing/discuss/379095/C%2B%2B-DFS-%2B-Memo
class Solution {
    int dp[2001][2001] = {};
    int dfs(vector<int>& A, vector<int>& B, int i, int j, int prev) {
        if (i >= A.size()) return 1;
        j = upper_bound(B.begin() + j, B.end(), prev) - B.begin();
        if (dp[i][j]) return dp[i][j];
        int skip = prev < A[i] ? dfs(A, B, i + 1, j, A[i]) : B.size() + 1;
        int swap = j < B.size() ? 1 + dfs(A, B, i + 1, j, B[j]) : B.size() + 1;
        return dp[i][j] = min(skip, swap);
    }
public:
    int makeArrayIncreasing(vector<int>& A, vector<int>& B) {
        sort(B.begin(), B.end());
        auto ans = dfs(A, B, 0, 0, INT_MIN);
        return ans > B.size() ? -1 : ans - 1;
    }
};