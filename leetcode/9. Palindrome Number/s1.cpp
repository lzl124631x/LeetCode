// OJ: https://leetcode.com/problems/palindrome-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long a = x, b = 0;
        while (x) {
            b = b * 10 + x % 10;
            x /= 10;
        }
        return a == b;
    }
};