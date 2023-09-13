// OJ: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
// Author: github.com/lzl124631x
// Time: O(MN + MlogM)
// Space: O(M)
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> v;
        for (int i = 0; i < mat.size(); ++i) {
            int cnt = 0;
            for (int j = 0; j < mat[i].size() && mat[i][j]; ++j) ++cnt;
            v.emplace_back(cnt, i);
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        for (int i = 0; i < k; ++i) ans.push_back(v[i].second);
        return ans;
    }
};