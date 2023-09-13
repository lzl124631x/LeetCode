# [1015. Smallest Integer Divisible by K (Medium)](https://leetcode.com/problems/smallest-integer-divisible-by-k/)

<p>Given a positive integer <code>k</code>, you need to find the <strong>length</strong> of the <strong>smallest</strong> positive integer <code>n</code> such that <code>n</code> is divisible by <code>k</code>, and <code>n</code> only contains the digit <code>1</code>.</p>

<p>Return <em>the <strong>length</strong> of </em><code>n</code>. If there is no such <code>n</code>, return -1.</p>

<p><strong>Note:</strong> <code>n</code> may not fit in a 64-bit signed integer.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> k = 1
<strong>Output:</strong> 1
<strong>Explanation:</strong> The smallest answer is n = 1, which has length 1.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> k = 2
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is no such positive integer n divisible by 2.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> k = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> The smallest answer is n = 111, which has length 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/smallest-integer-divisible-by-k/
// Author: github.com/lzl124631x
// Time: O(K)
// Space: O(K)
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        unordered_set<int> s;
        for (int n = 1 % k, len = 1; true; n = (n * 10 + 1) % k, ++len) {
            if (n == 0) return len;
            if (s.count(n)) return -1;
            s.insert(n);
        }
    }
};
```

Or using the Pigeonhole Principle

```cpp
// OJ: https://leetcode.com/problems/smallest-integer-divisible-by-k/
// Author: github.com/lzl124631x
// Time: O(K)
// Space: O(1)
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        for (int n = 1 % k, len = 1; len <= k; n = (n * 10 + 1) % k, ++len) {
            if (n == 0) return len;
        }
        return -1;
    }
};
```