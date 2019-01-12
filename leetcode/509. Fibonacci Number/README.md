# [509. Fibonacci Number (Easy)](https://leetcode.com/problems/fibonacci-number/)

<p>The&nbsp;<b>Fibonacci numbers</b>, commonly denoted&nbsp;<code>F(n)</code>&nbsp;form a sequence, called the&nbsp;<b>Fibonacci sequence</b>, such that each number is the sum of the two preceding ones, starting from <code>0</code> and <code>1</code>. That is,</p>

<pre>F(0) = 0,&nbsp; &nbsp;F(1)&nbsp;= 1
F(N) = F(N - 1) + F(N - 2), for N &gt; 1.
</pre>

<p>Given <code>N</code>, calculate <code>F(N)</code>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> 2
<strong>Output:</strong> 1
<strong>Explanation:</strong> F(2) = F(1) + F(0) = 1 + 0 = 1.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> F(3) = F(2) + F(1) = 1 + 1 = 2.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> 4
<strong>Output:</strong> 3
<strong>Explanation:</strong> F(4) = F(3) + F(2) = 2 + 1 = 3.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<p>0 ≤ <code>N</code> ≤ 30.</p>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Climbing Stairs (Easy)](https://leetcode.com/problems/climbing-stairs/)
* [Split Array into Fibonacci Sequence (Medium)](https://leetcode.com/problems/split-array-into-fibonacci-sequence/)
* [Length of Longest Fibonacci Subsequence (Medium)](https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/fibonacci-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int fib(int N) {
        if (!N) return 0;
        if (N == 1) return 1;
        int prev = 0, cur = 1;
        while (--N > 0) {
            int tmp = prev + cur;
            prev = cur;
            cur = tmp;
        }
        return cur;
    }
};
```