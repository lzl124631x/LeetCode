// OJ: https://leetcode.com/problems/day-of-the-year/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
    const int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    bool isLeap(int y) {
        return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
    }
public:
    int dayOfYear(string date) {
        int y = stoi(date.substr(0, 4)), m = stoi(date.substr(5, 2)), d = stoi(date.substr(8));
        return (m > 2 && isLeap(y)) + accumulate(begin(days), begin(days) + m - 1, 0) + d;
    }
};