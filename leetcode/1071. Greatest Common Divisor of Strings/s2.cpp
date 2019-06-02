// OJ: https://leetcode.com/problems/greatest-common-divisor-of-strings/
// Author: github.com/lzl124631x
// Time: O(SH) where S is string length and H is depth of recursion
// Space: O(SH)
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() < str2.size()) return gcdOfStrings(str2, str1);
        if (str2.empty()) return str1;
        auto d = str1.substr(0, str2.size());
        return d == str2 ? gcdOfStrings(str1.substr(str2.size()), str2) : "";
    }
};