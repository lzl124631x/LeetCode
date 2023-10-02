# [1716. Calculate Money in Leetcode Bank (Easy)](https://leetcode.com/problems/calculate-money-in-leetcode-bank/)

<p>Hercy wants to save money for his first car. He puts money in the Leetcode&nbsp;bank <strong>every day</strong>.</p>

<p>He starts by putting in <code>$1</code> on Monday, the first day. Every day from Tuesday to Sunday, he will put in <code>$1</code> more than the day before. On every subsequent Monday, he will put in <code>$1</code> more than the <strong>previous Monday</strong>.<span style="display: none;"> </span></p>

<p>Given <code>n</code>, return <em>the total amount of money he will have in the Leetcode bank at the end of the </em><code>n<sup>th</sup></code><em> day.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 4
<strong>Output:</strong> 10
<strong>Explanation:</strong>&nbsp;After the 4<sup>th</sup> day, the total is 1 + 2 + 3 + 4 = 10.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 10
<strong>Output:</strong> 37
<strong>Explanation:</strong>&nbsp;After the 10<sup>th</sup> day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37. Notice that on the 2<sup>nd</sup> Monday, Hercy only puts in $2.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 20
<strong>Output:</strong> 96
<strong>Explanation:</strong>&nbsp;After the 20<sup>th</sup> day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/calculate-money-in-leetcode-bank/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int totalMoney(int n) {
        int s = 1, ans = 0;
        while (n > 0) {
            for (int i = 0; i < 7 && n-- > 0; ++i) ans += s + i;
            s++;
        }
        return ans;
    }
};
```

## Solution 2. Math

We have `f = n / 7` full weeks. 

The first week we deposit `(1 + 7) * 7 / 2 = 28` dollars.

The `w`th week we deposit `(w + w + 6) * 7 / 2 = (w + 3) * 7` dollars, the `w + 1`th week we deposit `7` dollars more.

So the money we deposit each week is also an arithmetic sequence, whose sum is `(28 + 28 + 7 * (f - 1)) * f / 2 = (49 + 7 * f) * f / 2`.

The last non-full week has `d = n % 7` days. We deposit `f + 1` dollars on its Monday, so we deposit `(f + 1 + (f + 1 + d - 1)) * d / 2 = (2 * f + d + 1) * d / 2` dollars for this week.

So the final answer is `(49 + 7 * f) * f / 2 + (2 * f + d + 1) * d / 2`.

```cpp
// OJ: https://leetcode.com/problems/calculate-money-in-leetcode-bank/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int totalMoney(int n) {
        int f = n / 7, d = n % 7;
        return (49 + 7 * f) * f / 2 + (2 * f + d + 1) * d / 2;
    }
};
```