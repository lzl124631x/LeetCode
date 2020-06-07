// OJ: https://leetcode.com/problems/queue-reconstruction-by-height
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/60470/6-lines-concise-c
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });
        vector<vector<int>> ans;
        for (auto &p : people) ans.insert(ans.begin() + p[1], p);
        return ans;
    }
};