// OJ: https://leetcode.com/problems/reverse-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) swap(s[i++], s[j--]);
    }
};