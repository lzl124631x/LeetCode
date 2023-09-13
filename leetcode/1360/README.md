# [1360. Number of Days Between Two Dates (Easy)](https://leetcode.com/problems/number-of-days-between-two-dates/)

<p>Write a program to count the number of days between two dates.</p>

<p>The two dates are given as strings, their format is <code>YYYY-MM-DD</code>&nbsp;as shown in the examples.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> date1 = "2019-06-29", date2 = "2019-06-30"
<strong>Output:</strong> 1
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> date1 = "2020-01-15", date2 = "2019-12-31"
<strong>Output:</strong> 15
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The given dates are valid&nbsp;dates between the years <code>1971</code> and <code>2100</code>.</li>
</ul>


## Solution 1.

```cpp
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
```

## Solution 2. Magic Formula

When `m=1` or `m=2` (January or February), we let `m=13` or `m=14` and let `y` decreased by 1. Imagine it is 13th or 14th month of the last year. By doing that, we let the magical formula also work for those two months. `(153 * m + 8) // 5` is just a carefully designed way to record the days of each month. More specifically, it is designed to record the difference of days between two months. Suppose we have March 1st and April 1st, `(153 * 3 + 8) // 5 = 93` while `(153 * 4 + 8) // 5 = 124`, the difference is 31 which is the number of days in March. Suppose we have April 1st to May 1st, `(153 * 4 + 8) // 5 = 124` and `(153 * 5 + 8) // 5 = 154`, the difference is now 30 which is the number of days in April. You can also check other months.

```cpp
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
```