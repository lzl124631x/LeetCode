// OJ: https://leetcode.com/problems/reverse-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string reverseString(string s) {
    	return string(s.rbegin(), s.rend());
    }
};