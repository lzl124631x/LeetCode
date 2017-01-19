// Brute Force
// Time: O(n^2)
// Space: O(1)

class Solution {
private:
    bool isPalindrome(string &s, int start, int end) {
        int len = end - start + 1;
        int L = start + len / 2 - 1, R = end - len / 2 + 1;
        while (L >= start && s[L] == s[R]) --L, ++R;
        return L < start;
    }
public:
    string shortestPalindrome(string s) {
        int end = s.size() - 1;
        for (; end >= 0 && !isPalindrome(s, 0, end); --end);
        string prefix(s.rbegin(), s.rend() - end - 1);
        return prefix + s;
    }
};