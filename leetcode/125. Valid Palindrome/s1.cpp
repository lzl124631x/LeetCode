// OJ: https://leetcode.com/problems/valid-palindrome/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size();
        while (i < j) {
            while (i < j && !isalnum(s[i])) ++i;
            while (i < j && !isalnum(s[j])) --j;
            if (i < j && tolower(s[i++]) != tolower(s[j--])) return false;
        }
        return true;
    }
};