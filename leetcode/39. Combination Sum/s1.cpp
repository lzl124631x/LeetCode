// OJ: https://leetcode.com/problems/combination-sum/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
    vector<vector<int>> dfs(vector<int>& A, int target, int start) {
        if (!target) return {{}};
        if (start == A.size()) return {};
        int n = A[start];
        auto ans = dfs(A, target, start + 1);
        if (target >= n) {
            auto tmp = dfs(A, target - n, start);
            for (auto v : tmp) {
                v.push_back(n);
                ans.push_back(v);
            }
        }
        return ans;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& A, int target) {
        return dfs(A, target, 0);
    }
};