// OJ: https://leetcode.com/problems/to-lower-case/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string toLowerCase(string str) {
        for (char &c : str) c = tolower(c);
        return str;
    }
};