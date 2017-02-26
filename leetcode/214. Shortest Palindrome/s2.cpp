// https://discuss.leetcode.com/topic/14770/my-easily-understandable-but-time-consuming-c-solution
// Brute force
// Time: O(n^2)
// 86 ms
class Solution {
public:
    string shortestPalindrome(string s) {
        string r(s.rbegin(), s.rend());
        int n = s.size(), l = n;
        while (l >= 0 && s.substr(0, l) != r.substr(n - l)) --l;
        return r.substr(0, n - l) + s;
    }
};