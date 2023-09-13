// OJ: https://leetcode.com/problems/number-of-days-between-two-dates/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
// Ref: https://leetcode.com/problems/number-of-days-between-two-dates/discuss/517605/Similar-to-day-of-the-year
class Solution {
    const int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    bool isLeap(int year) {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }
    int daysFrom1971(string date) {
        int y = stoi(date.substr(0, 4)), m = stoi(date.substr(5, 2)), d = stoi(date.substr(8));
        for (int yr = 1971; yr < y; ++yr) d += isLeap(yr) ? 366 : 365;
        return d + (m > 2 && isLeap(y)) + accumulate(begin(days), begin(days) + m - 1, 0);
    } 
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(daysFrom1971(date1) - daysFrom1971(date2));
    }
};