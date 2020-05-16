// OJ: https://leetcode.com/problems/consecutive-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxPower(string s) {
        int ans = 1, cnt = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) ans = max(ans, ++cnt);
            else cnt = 1;
        }
        return ans;
    }
};