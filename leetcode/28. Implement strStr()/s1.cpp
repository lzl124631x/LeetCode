// OJ: https://leetcode.com/problems/implement-strstr/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) return -1;
        for (int i = 0; i <= haystack.size() - needle.size(); ++i) {
            int j = 0;
            for (; j < needle.size() && haystack[i + j] == needle[j]; ++j);
            if (j == needle.size()) return i;
        }
        return -1;
    }
};