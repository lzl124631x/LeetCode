// OJ: https://leetcode.com/problems/range-addition/
// Author: github.com/lzl124631x
// Time: O(N+U)
// Space: O(1)
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length, 0);
        for (auto &u : updates) {
            int start = u[0], end = u[1], val = u[2];
            ans[start] += val;
            if (end + 1 < length) ans[end + 1] -= val;
        }
        partial_sum(ans.begin(), ans.end(), ans.begin());
        return ans;
    }
};