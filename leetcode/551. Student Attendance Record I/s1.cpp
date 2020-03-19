// OJ: https://leetcode.com/problems/student-attendance-record-i/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool checkRecord(string s) {
        int A = 0, L = 0;
        for (char c : s) {
            if (c == 'A') ++A;
            if (c == 'L') ++L;
            else L = 0;
            if (A > 1 || L > 2) return false;
        }
        return true;
    }
};