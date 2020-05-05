// OJ: https://leetcode.com/problems/minimum-number-of-frogs-croaking/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minNumberOfFrogs(string s) {
        string t = "croak";
        vector<int> cnt(5);
        int ans = 0, cur = 0;
        for (char c : s) {
            int n = t.find(c);
            if (n == string::npos) return -1;
            if (n != 0 && --cnt[n - 1] < 0) return -1;
            ++cnt[n];
            if (n == 0) ++cur;
            else if (n == 4) --cur;
            ans = max(ans, cur);
        }
        return cur ? -1 : ans;
    }
};