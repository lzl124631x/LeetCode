// OJ: https://leetcode.com/problems/maximum-number-of-balloons/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cnt[26] = {0};
        for (char c : text) cnt[c - 'a']++;
        return min(min(cnt['b' - 'a'], min(cnt['a' - 'a'], cnt['n' - 'a'])),
            min(cnt['l' - 'a'] / 2, cnt['o' - 'a'] / 2));
    }
};