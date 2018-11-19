// OJ: https://leetcode.com/problems/daily-temperatures/
// Author: github.com/lzl124631x
// Time: O(T)
// Space: O(T)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> indexes(T.size()), vals(T.size()), ans(T.size());
        int length = 0;
        for (int i = T.size() - 1; i >= 0; --i) {
            auto p = lower_bound(vals.begin(), vals.begin() + length, T[i], greater<int>());
            int pos = p - vals.begin();
            vals[pos] = T[i];
            indexes[pos] = i;
            length = pos + 1;
            ans[i] = pos > 0 ? indexes[pos - 1] - i : 0;
        }
        return ans;
    }
};