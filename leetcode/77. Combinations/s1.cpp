// OJ: https://leetcode.com/problems/combinations/
// Author: github.com/lzl124631x
// Time: O(K!)
// Space: O(K)
class Solution {
private:
    vector<vector<int>> ans;
    void dfs(int start, int n, int k, vector<int>& tmp) {
        if (tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }
        for (int i = start; i <= n - k + 1 + tmp.size(); ++i) {
            tmp.push_back(i);
            dfs(i + 1, n, k, tmp);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        dfs(1, n, k, tmp);
        return ans;
    }
};