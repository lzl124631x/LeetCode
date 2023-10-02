# [2507. Smallest Value After Replacing With Sum of Prime Factors (Medium)](https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors)

<p>You are given a positive integer <code>n</code>.</p>
<p>Continuously replace <code>n</code> with the sum of its <strong>prime factors</strong>.</p>
<ul>
	<li>Note that if a prime factor divides <code>n</code> multiple times, it should be included in the sum as many times as it divides <code>n</code>.</li>
</ul>
<p>Return <em>the smallest value </em><code>n</code><em> will take on.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> n = 15
<strong>Output:</strong> 5
<strong>Explanation:</strong> Initially, n = 15.
15 = 3 * 5, so replace n with 3 + 5 = 8.
8 = 2 * 2 * 2, so replace n with 2 + 2 + 2 = 6.
6 = 2 * 3, so replace n with 2 + 3 = 5.
5 is the smallest value n will take on.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> n = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> Initially, n = 3.
3 is the smallest value n will take on.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Number Theory](https://leetcode.com/tag/number-theory/)

**Similar Questions**:
* [Happy Number (Easy)](https://leetcode.com/problems/happy-number/)
* [2 Keys Keyboard (Medium)](https://leetcode.com/problems/2-keys-keyboard/)
* [Count Ways to Make Array With Product (Hard)](https://leetcode.com/problems/count-ways-to-make-array-with-product/)
* [Distinct Prime Factors of Product of Array (Medium)](https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors
// Author: github.com/lzl124631x
// Time: O(Sqrt(N))
// Space: O(Sqrt(N))
class Solution {
    vector<int> factors(int n) {
        vector<int> ans;
        for (int i = 2; i * i <= n; ++i) {
            while (n % i == 0) {
                n /= i;
                ans.push_back(i);
            }
        }
        if (n > 1) ans.push_back(n);
        return ans;
    }
public:
    int smallestValue(int n) {
        while (true) {
            auto fs = factors(n);
            int m = accumulate(begin(fs), end(fs), 0);
            if (m == n) return n;
            n = m;
        }
    }
};
```