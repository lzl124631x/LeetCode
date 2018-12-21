// OJ: https://leetcode.com/problems/palindrome-permutation/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> cnts;
        for (char c : s) cnts[c]++;
        bool foundSingle = false;
        for (auto &p : cnts) {
            if (p.second % 2) {
                if (foundSingle) return false;
                foundSingle = true;
            }
        }
        return true;
    }
};