# [1553. Minimum Number of Days to Eat N Oranges (Hard)](https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/)

<p>There are <code>n</code> oranges in the kitchen and you decided to eat some of these oranges every day as follows:</p>

<ul>
	<li>Eat one orange.</li>
	<li>If the number of remaining oranges (<code>n</code>) is divisible by 2 then you can eat&nbsp; n/2 oranges.</li>
	<li>If the number of remaining oranges (<code>n</code>) is divisible by 3&nbsp;then you can eat&nbsp; 2*(n/3)&nbsp;oranges.</li>
</ul>

<p>You can only choose one of the actions per day.</p>

<p>Return the minimum number of days to eat <code>n</code> oranges.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 10
<strong>Output:</strong> 4
<strong>Explanation:</strong> You have 10 oranges.
Day 1: Eat 1 orange,  10 - 1 = 9.  
Day 2: Eat 6 oranges, 9 - 2*(9/3) = 9 - 6 = 3. (Since 9 is divisible by 3)
Day 3: Eat 2 oranges, 3 - 2*(3/3) = 3 - 2 = 1. 
Day 4: Eat the last orange  1 - 1  = 0.
You need at least 4 days to eat the 10 oranges.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 6
<strong>Output:</strong> 3
<strong>Explanation:</strong> You have 6 oranges.
Day 1: Eat 3 oranges, 6 - 6/2 = 6 - 3 = 3. (Since 6 is divisible by 2).
Day 2: Eat 2 oranges, 3 - 2*(3/3) = 3 - 2 = 1. (Since 3 is divisible by 3)
Day 3: Eat the last orange  1 - 1  = 0.
You need at least 3 days to eat the 6 oranges.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 1
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> n = 56
<strong>Output:</strong> 6
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2*10^9</code></li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

The idea of the solution is not hard -- basically use DFS to try `n-1`, `n/2`, `n/3` cases and memoize the minimal value.

One caveat is that we shouldn't do `n-1` case every time because that will regress our solution to `O(N)` time complexity.

In fact, we should eat `n % 2` oranges one-by-one and then swallow `n / 2`, or eat `n % 3` oranges so that we can gobble `2 * n / 3`.

We need to prove that this works. This solution can be expressed as "we should never take more than 2 consecutive `-1` operations".

We can prove by contradiction:

Assume there exits some `n` that we need to take `3` consecutive `-1` operations for optimal solution, i.e. `minDays(n) = minDays(n - 3) + 3`.

If the first operation we take for `n - 3` is `/2`, then `n` is odd. Since `(n - 3) / 2 = (n - 1) / 2 - 1`, we can see that taking `-1, /2, -1` `3` operations is better than taking `-1, -1, -1, /2` `4` operations. So taking `3` `-1` operations is not optimal in this case.

If the first operation we take for `n - 3` is `/3`, so `n` is divisible by `3`. Since `(n - 3) / 3 = n / 3 - 1`, we can see that taking `/3, -1` `2` operations is better than taking `-1, -1, -1, /3` `4` operations. So taking `3` `-1` operations is not optimal in this case.

This process can be extended to taking `k >= 3` consecutive `-1`s.

Thus the conclusion is taht we should always at most take `2` consecutive `-1` operations.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(logN)
class Solution {
    unordered_map<int, int> m;
public:
    int minDays(int n) {
        if (n <= 1) return n;
        if (m.count(n)) return m[n];
        return m[n] = 1 + min(minDays(n / 3) + n % 3, minDays(n / 2) + n % 2);
    }
};
```