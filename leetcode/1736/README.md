# [1736. Latest Time by Replacing Hidden Digits (Easy)](https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/submissions/)

<p>You are given a string <code>time</code> in the form of <code> hh:mm</code>, where some of the digits in the string are hidden (represented by <code>?</code>).</p>

<p>The valid times are those inclusively between <code>00:00</code> and <code>23:59</code>.</p>

<p>Return <em>the latest valid time you can get from</em> <code>time</code><em> by replacing the hidden</em> <em>digits</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> time = "2?:?0"
<strong>Output:</strong> "23:50"
<strong>Explanation:</strong> The latest hour beginning with the digit '2' is 23 and the latest minute ending with the digit '0' is 50.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> time = "0?:3?"
<strong>Output:</strong> "09:39"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> time = "1?:22"
<strong>Output:</strong> "19:22"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>time</code> is in the format <code>hh:mm</code>.</li>
	<li>It is guaranteed that you can produce a valid time from the given string.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    string maximumTime(string time) {
        if (time[0] == '?') time[0] = time[1] == '?' || time[1] <= '3' ? '2' : '1';
        if (time[1] == '?') time[1] = time[0] == '2' ? '3' : '9';
        if (time[3] == '?') time[3] = '5';
        if (time[4] == '?') time[4] = '9';
        return time;
    }
};
```