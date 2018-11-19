// OJ: https://leetcode.com/problems/daily-temperatures/
// Author: github.com/lzl124631x
// Time: O(T)
// Space: O(T)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
        vector<int> ans(T.size());
        for (int i = T.size() - 1; i >= 0; --i) {
            while (s.size() && T[s.top()] <= T[i]) s.pop();
            ans[i] = s.size() ? s.top() - i : 0;
            s.push(i);
        }
        return ans;
    }
};