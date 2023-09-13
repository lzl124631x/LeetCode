# [2571. Minimum Operations to Reduce an Integer to 0 (Medium)](https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0)

<p>You are given a positive integer <code>n</code>, you can do the following operation <strong>any</strong> number of times:</p>
<ul>
	<li>Add or subtract a <strong>power</strong> of <code>2</code> from <code>n</code>.</li>
</ul>
<p>Return <em>the <strong>minimum</strong> number of operations to make </em><code>n</code><em> equal to </em><code>0</code>.</p>
<p>A number <code>x</code> is power of <code>2</code> if <code>x == 2<sup>i</sup></code>&nbsp;where <code>i &gt;= 0</code><em>.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> n = 39
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can do the following operations:
- Add 2<sup>0</sup> = 1 to n, so now n = 40.
- Subtract 2<sup>3</sup> = 8 from n, so now n = 32.
- Subtract 2<sup>5</sup> = 32 from n, so now n = 0.
It can be shown that 3 is the minimum number of operations we need to make n equal to 0.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> n = 54
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can do the following operations:
- Add 2<sup>1</sup> = 2 to n, so now n = 56.
- Add 2<sup>3</sup> = 8 to n, so now n = 64.
- Subtract 2<sup>6</sup> = 64 from n, so now n = 0.
So the minimum number of operations is 3.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>

**Companies**:
[Nvidia](https://leetcode.com/company/nvidia)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Greedy](https://leetcode.com/tag/greedy/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Plus One (Easy)](https://leetcode.com/problems/plus-one/)

## Solution 1. Greedy

```cpp
// OJ: https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int minOperations(int n) {
        int ans = 0, one = 0;
        while (n) {
            int zero = 0;
            while (n & 1) n >>= 1, ++one;
            while (n && (n & 1) == 0) n >>= 1, ++zero;
            if (one == 1) ++ans, one = 0; // a single 1 -> remove it directly
            else if (one) { // For multiple 1s, we add at the rightmost 1. For example, 00111 -> 01000
                if (zero == 1) ++ans, one = 1; // if there is only a single leading 0, this new 1 is merged with the next batch of ones.
                else ans += 2, one = 0; // if there are multiple leading 0s, we remove this new 1
            }
        }
        return ans;
    }
};
```