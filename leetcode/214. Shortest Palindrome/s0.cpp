// Time: 269 ms
class Solution {
private:
    bool isPalindrome(string &s, int start, int end) {
        while (start < end && s[start] == s[end]) ++start, --end;
        return start >= end;
    }
public:
    string shortestPalindrome(string s) {
        int end = s.size() - 1;
        for (; end >= 0 && !isPalindrome(s, 0, end); --end);
        string prefix(s.rbegin(), s.rend() - end - 1);
        return prefix + s;
    }
};