// OJ: https://leetcode.com/problems/number-of-days-between-two-dates/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
// Ref: https://leetcode.com/problems/number-of-days-between-two-dates/discuss/517582/Python-Magical-Formula
class Solution {
    int days(string date) {
        int y = stoi(date.substr(0, 4)), m = stoi(date.substr(5, 2)), d = stoi(date.substr(8));
        if (m < 3) {
            m += 12;
            y -= 1;
        }
        return 365 * y + y / 4 + y / 400 - y / 100 + d + (153 * m + 8) / 5;
    }
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(days(date1) - days(date2));
    }
};