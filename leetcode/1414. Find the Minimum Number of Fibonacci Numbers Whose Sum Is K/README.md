# [1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K (Medium)](https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/)

<p>Given the number <code>k</code>, <em>return the minimum number of Fibonacci numbers whose sum is equal to </em><code>k</code>, whether a Fibonacci number could be used multiple times.</p>

<p>The Fibonacci numbers are defined as:</p>

<ul>
	<li>F<sub>1</sub> = 1</li>
	<li>F<sub>2</sub> = 1</li>
	<li>F<sub>n</sub> = F<sub>n-1</sub> + F<sub>n-2</sub> , for n &gt; 2.</li>
</ul>
It is guaranteed that for the given constraints we can always find such fibonacci numbers that sum <code>k</code>.
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> k = 7
<strong>Output:</strong> 2 
<strong>Explanation:</strong> The Fibonacci numbers are: 1, 1, 2, 3, 5, 8, 13, ... 
For k = 7 we can use 2 + 5 = 7.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> k = 10
<strong>Output:</strong> 2 
<strong>Explanation:</strong> For k = 10 we can use 2 + 8 = 10.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> k = 19
<strong>Output:</strong> 3 
<strong>Explanation:</strong> For k = 19 we can use 1 + 5 + 13 = 19.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 10^9</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. Greedy

We greedily find the maximum fibonacci number that is smaller or equal to `k`.

Assume it's `b`, then `f(k) = f(k-b) + 1`. `f(0) = 0`.

```cpp
// OJ: https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/
// Author: github.com/lzl124631x
// Time: O(F(k)) where F(k) is the steps to compute the fibonacci number greater than k
// Space: O(1)
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        if (k == 0) return 0;
        int a = 1, b = 1;
        while (a + b <= k) {
            int c = a + b;
            a = b;
            b = c;
        }
        return findMinFibonacciNumbers(k - b) + 1;
    }
};
```