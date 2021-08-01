# [1952. Three Divisors (Easy)](https://leetcode.com/problems/three-divisors/)

<p>Given an integer <code>n</code>, return <code>true</code><em> if </em><code>n</code><em> has <strong>exactly three positive divisors</strong>. Otherwise, return </em><code>false</code>.</p>

<p>An integer <code>m</code> is a <strong>divisor</strong> of <code>n</code> if there exists an integer <code>k</code> such that <code>n = k * m</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> false
<strong>Explantion:</strong> 2 has only two divisors: 1 and 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 4
<strong>Output:</strong> true
<strong>Explantion:</strong> 4 has three divisors: 1, 2, and 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>


## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/three-divisors/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isThree(int n) {
        int ans = 0;
        for (int i = 1; i <= n && ans <= 3; ++i) {
            if (n % i == 0) ++ans;
        }
        return ans == 3;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/three-divisors/
// Author: github.com/lzl124631x
// Time: O(sqrt(N))
// Space: O(1)
class Solution {
public:
    bool isThree(int n) {
        int ans = 0;
        for (int i = 1; i * i <= n && ans <= 3; ++i) {
            if (n % i == 0) {
                ++ans;
                if (n / i != i) ++ans;
            }
        }
        return ans == 3;
    }
};
```