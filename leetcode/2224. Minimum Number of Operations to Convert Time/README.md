# [2224. Minimum Number of Operations to Convert Time (Easy)](https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/)

<p>You are given two strings <code>current</code> and <code>correct</code> representing two <strong>24-hour times</strong>.</p>

<p>24-hour times are formatted as <code>"HH:MM"</code>, where <code>HH</code> is between <code>00</code> and <code>23</code>, and <code>MM</code> is between <code>00</code> and <code>59</code>. The earliest 24-hour time is <code>00:00</code>, and the latest is <code>23:59</code>.</p>

<p>In one operation you can increase the time <code>current</code> by <code>1</code>, <code>5</code>, <code>15</code>, or <code>60</code> minutes. You can perform this operation <strong>any</strong> number of times.</p>

<p>Return <em>the <strong>minimum number of operations</strong> needed to convert </em><code>current</code><em> to </em><code>correct</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> current = "02:30", correct = "04:35"
<strong>Output:</strong> 3
<strong>Explanation:
</strong>We can convert current to correct in 3 operations as follows:
- Add 60 minutes to current. current becomes "03:30".
- Add 60 minutes to current. current becomes "04:30".
- Add 5 minutes to current. current becomes "04:35".
It can be proven that it is not possible to convert current to correct in fewer than 3 operations.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> current = "11:00", correct = "11:01"
<strong>Output:</strong> 1
<strong>Explanation:</strong> We only have to add one minute to current, so the minimum number of operations needed is 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>current</code> and <code>correct</code> are in the format <code>"HH:MM"</code></li>
	<li><code>current &lt;= correct</code></li>
</ul>


**Similar Questions**:
* [Coin Change (Medium)](https://leetcode.com/problems/coin-change/)

## Solution 1. Greedy

* Compute the time difference in seconds
* Greedily using `60, 15, 5, 1` operations. For each operation `op`, we use `diff / op` number of operations to turn `diff` to `diff % op`.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
    int getTime(string &s) {
        return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
    }
public:
    int convertTime(string current, string correct) {
        int diff = getTime(correct) - getTime(current), ops[4] = {60,15,5,1}, ans = 0;
        for (int op : ops) {
            ans += diff / op;
            diff %= op;
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/discuss/1908782/