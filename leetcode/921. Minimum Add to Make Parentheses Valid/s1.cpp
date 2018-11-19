// OJ: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minAddToMakeValid(string S) {
        int left = 0, invalidRight = 0;
        for (char c : S) {
            if (c == '(') left++;
            else if (!left) invalidRight++;
            else --left;
        }
        return left + invalidRight;
    }
};