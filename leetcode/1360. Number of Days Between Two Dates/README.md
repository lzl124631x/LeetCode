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