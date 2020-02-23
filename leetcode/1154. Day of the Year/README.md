# [1154. Day of the Year (Easy)](https://leetcode.com/problems/day-of-the-year/)

<p>Given a string <code>date</code> representing a <a href="https://en.wikipedia.org/wiki/Gregorian_calendar" target="_blank">Gregorian&nbsp;calendar</a> date formatted as <code>YYYY-MM-DD</code>, return the day number of the year.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> date = "2019-01-09"
<strong>Output:</strong> 9
<strong>Explanation:</strong> Given date is the 9th day of the year in 2019.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> date = "2019-02-10"
<strong>Output:</strong> 41
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> date = "2003-03-01"
<strong>Output:</strong> 60
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> date = "2004-03-01"
<strong>Output:</strong> 61
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>date.length == 10</code></li>
	<li><code>date[4] == date[7] == '-'</code>, and all other <code>date[i]</code>'s are digits</li>
	<li><code>date</code> represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.</li>
</ul>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
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
```