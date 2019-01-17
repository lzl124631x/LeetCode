// OJ: https://leetcode.com/problems/minimum-window-substring/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://discuss.leetcode.com/topic/30941/here-is-a-10-line-template-that-can-solve-most-substring-problems
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(128, 0);
        for (char c : t) ++m[c];
        int begin = 0, end = 0, head = 0, cnt = t.size(), len = INT_MAX;
        while (end < s.size()) {
            if (m[s[end++]]-- > 0) --cnt;
            while (!cnt) {
                if (end - begin < len) len = end - (head = begin);
                if (m[s[begin++]]++ == 0) ++cnt;
            }
        }
        return len == INT_MAX ? "" : s.substr(head, len);
    }
};