// OJ: https://leetcode.com/problems/longest-uncommon-subsequence-i/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a.size() != b.size()) return max(a.size(), b.size());
        return a == b ? -1 : a.size();
    }
};