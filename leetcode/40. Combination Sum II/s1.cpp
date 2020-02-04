// OJ: https://leetcode.com/problems/combination-sum-ii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
    vector<vector<int>> ans;
    void dfs(vector<int> &A, int target, int start, vector<int> &tmp) {
        if (!target) {
            ans.push_back(tmp);
            return;
        }
        for (int i = start; i < A.size() && target >= A[i]; ++i) {
            if (i != start && A[i] == A[i - 1]) continue;
            tmp.push_back(A[i]);
            dfs(A, target - A[i], i + 1, tmp);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& A, int target) {
        sort(A.begin(), A.end());
        vector<int> tmp;
        dfs(A, target, 0, tmp);
        return ans;
    }
};