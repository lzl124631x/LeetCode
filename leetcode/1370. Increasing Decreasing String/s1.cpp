// OJ: https://leetcode.com/problems/increasing-decreasing-string
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string sortString(string s) {
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;
        int N = s.size();
        string ans(N, '\0');
        for (int i = 0; i < N; ) {
            for (int j = 0; j < 26; ++j) {
                if (!cnt[j]) continue;
                ans[i++] = 'a' + j;
                cnt[j]--;
            }
            for (int j = 25; j >= 0; --j) {
                if (!cnt[j]) continue;
                ans[i++] = 'a' + j;
                cnt[j]--;
            }
        }
        return ans;
    }
};