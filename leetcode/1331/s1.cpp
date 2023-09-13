// OJ: https://leetcode.com/problems/rank-transform-of-an-array/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s(arr.begin(), arr.end());
        unordered_map<int, int> m;
        vector<int> ans(arr.size(), 0);
        int i = 0;
        for (auto it = s.begin(); it != s.end(); ++it) m[*it] = ++i;
        for (int j = 0; j < arr.size(); ++j) ans[j] = m[arr[j]];
        return ans;
    }
};