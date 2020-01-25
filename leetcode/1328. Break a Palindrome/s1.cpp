// OJ: https://leetcode.com/problems/break-a-palindrome/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int N = palindrome.size(), end = N / 2;
        for (int i = 0; i < end; ++i) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        if (N > 1) {
            palindrome[N - 1] = 'b';
            return palindrome;
        }
        return "";
    }
};