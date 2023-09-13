// OJ: https://leetcode.com/problems/number-of-lines-to-write-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int lineWidth = 0, cnt = 1;
        for (char c : S) {
            if (lineWidth + widths[c - 'a'] > 100) {
                lineWidth = 0;
                ++cnt;
            }
            lineWidth += widths[c - 'a'];
        }
        return { cnt, lineWidth };
    }
};