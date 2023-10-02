// OJ: https://leetcode.com/problems/day-of-the-week/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
private:
    bool isLeapYear(int y) {
        return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
    }
    string dates[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
public:
    string dayOfTheWeek(int day, int month, int year) { // Compare it with 1971/1/1 (Friday)
        int d = 0;
        for (int y = 1971; y < year; ++y) d += 365 + (isLeapYear(y) ? 1 : 0);
        for (int m = 1; m < month; ++m) {
            if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10) d += 31;
            else if (m == 2) d += 28 + (isLeapYear(year) ? 1 : 0);
            else d += 30;
        }
        return dates[(d + day + 4) % 7];
    }
};