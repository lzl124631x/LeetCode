// OJ: https://leetcode.com/problems/valid-palindrome-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1, del = 1;
        for (; i < j; ++i, --j) {
            if (s[i] == s[j]) continue;
            if (isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1)) return true;
            return false;
        }
        return true;
    }
};