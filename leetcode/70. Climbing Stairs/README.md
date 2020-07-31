# [70. Climbing Stairs (Easy)](https://leetcode.com/problems/climbing-stairs/)

<p>You are climbing a stair case. It takes <em>n</em> steps to reach to the top.</p>

<p>Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 45</code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Min Cost Climbing Stairs (Easy)](https://leetcode.com/problems/min-cost-climbing-stairs/)
* [Fibonacci Number (Easy)](https://leetcode.com/problems/fibonacci-number/)
* [N-th Tribonacci Number (Easy)](https://leetcode.com/problems/n-th-tribonacci-number/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/climbing-stairs/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int climbStairs(int n) {
        int ans = 1, prev = 1;
        while (--n) {
            ans += prev;
            prev = ans - prev;
        }
        return ans;
    }
};
```