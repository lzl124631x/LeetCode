# [1185. Day of the Week (Easy)](https://leetcode.com/problems/day-of-the-week/)

<p>Given a date, return the corresponding day of the week for that date.</p>

<p>The input is given as three integers representing the <code>day</code>, <code>month</code> and <code>year</code> respectively.</p>

<p>Return the answer as one of the following values&nbsp;<code>{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> day = 31, month = 8, year = 2019
<strong>Output:</strong> "Saturday"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> day = 18, month = 7, year = 1999
<strong>Output:</strong> "Sunday"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> day = 15, month = 8, year = 1993
<strong>Output:</strong> "Sunday"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The given dates are valid&nbsp;dates between the years <code>1971</code> and <code>2100</code>.</li>
</ul>

**Companies**:  
[United Health Group](https://leetcode.com/company/united-health-group)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

Compute difference between the date and 1971/1/1 which is Friday.

When the input is exactly 1971/1/1, the `d + day` will be `1`. To get `Friday`, we need to shift it by `4`.

```cpp
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
```