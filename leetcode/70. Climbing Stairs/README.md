# [70. Climbing Stairs (Easy)](https://leetcode.com/problems/climbing-stairs/)

<p>You are climbing a staircase. It takes <code>n</code> steps to reach the top.</p>

<p>Each time you can either climb <code>1</code> or <code>2</code> steps. In how many distinct ways can you climb to the top?</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 3
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


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft), [Bloomberg](https://leetcode.com/company/bloomberg), [Expedia](https://leetcode.com/company/expedia), [Adobe](https://leetcode.com/company/adobe), [Uber](https://leetcode.com/company/uber), [Apple](https://leetcode.com/company/apple), [LinkedIn](https://leetcode.com/company/linkedin), [Facebook](https://leetcode.com/company/facebook), [Walmart Labs](https://leetcode.com/company/walmart-labs), [Morgan Stanley](https://leetcode.com/company/morgan-stanley), [Twilio](https://leetcode.com/company/twilio)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Memoization](https://leetcode.com/tag/memoization/)

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

Or

```cpp
// OJ: https://leetcode.com/problems/climbing-stairs/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int climbStairs(int n) {
        int prev = 0, cur = 1;
        while (n--) {
            int next = cur + prev;
            prev = cur;
            cur = next;
        }
        return cur;
    }
};
```