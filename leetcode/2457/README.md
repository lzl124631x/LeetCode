# [2457. Minimum Addition to Make Integer Beautiful (Medium)](https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful)

<p>You are given two positive integers <code>n</code> and <code>target</code>.</p>
<p>An integer is considered <strong>beautiful</strong> if the sum of its digits is less than or equal to <code>target</code>.</p>
<p>Return the <em>minimum <strong>non-negative</strong> integer </em><code>x</code><em> such that </em><code>n + x</code><em> is beautiful</em>. The input will be generated such that it is always possible to make <code>n</code> beautiful.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> n = 16, target = 6
<strong>Output:</strong> 4
<strong>Explanation:</strong> Initially n is 16 and its digit sum is 1 + 6 = 7. After adding 4, n becomes 20 and digit sum becomes 2 + 0 = 2. It can be shown that we can not make n beautiful with adding non-negative integer less than 4.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> n = 467, target = 6
<strong>Output:</strong> 33
<strong>Explanation:</strong> Initially n is 467 and its digit sum is 4 + 6 + 7 = 17. After adding 33, n becomes 500 and digit sum becomes 5 + 0 + 0 = 5. It can be shown that we can not make n beautiful with adding non-negative integer less than 33.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> n = 1, target = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> Initially n is 1 and its digit sum is 1, which is already smaller than or equal to target.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>12</sup></code></li>
	<li><code>1 &lt;= target &lt;= 150</code></li>
	<li>The input will be generated such that it is always possible to make <code>n</code> beautiful.</li>
</ul>

**Companies**:
[Infosys](https://leetcode.com/company/infosys)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Happy Number (Easy)](https://leetcode.com/problems/happy-number/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful
// Author: github.com/lzl124631x
// Time: O((lgN)^2)
// Space: O(1)
class Solution {
    long long sumDigits(long long n) {
        long long ans = 0;
        while (n) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long p = 1, ans = 0;
        while (sumDigits(n) > target) {
            while (n / p % 10 == 0) p *= 10;
            long long d = 10 - n / p % 10;
            n += d * p;
            ans += d * p;
        }
        return ans;
    }
};
```