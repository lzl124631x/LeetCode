# [2749. Minimum Operations to Make the Integer Zero (Medium)](https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero)

<p>You are given two integers <code>num1</code> and <code>num2</code>.</p>
<p>In one operation, you can choose integer <code>i</code> in the range <code>[0, 60]</code> and subtract <code>2<sup>i</sup> + num2</code> from <code>num1</code>.</p>
<p>Return <em>the integer denoting the <strong>minimum</strong> number of operations needed to make</em> <code>num1</code> <em>equal to</em> <code>0</code>.</p>
<p>If it is impossible to make <code>num1</code> equal to <code>0</code>, return <code>-1</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> num1 = 3, num2 = -2
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can make 3 equal to 0 with the following operations:
- We choose i = 2 and substract 2<sup>2</sup> + (-2) from 3, 3 - (4 + (-2)) = 1.
- We choose i = 2 and substract 2<sup>2</sup>&nbsp;+ (-2) from 1, 1 - (4 + (-2)) = -1.
- We choose i = 0 and substract 2<sup>0</sup>&nbsp;+ (-2) from -1, (-1) - (1 + (-2)) = 0.
It can be proven, that 3 is the minimum number of operations that we need to perform.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> num1 = 5, num2 = 7
<strong>Output:</strong> -1
<strong>Explanation:</strong> It can be proven, that it is impossible to make 5 equal to 0 with the given operation.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= num1 &lt;= 10<sup>9</sup></code></li>
	<li><code><font face="monospace">-10<sup>9</sup>&nbsp;&lt;= num2 &lt;= 10<sup>9</sup></font></code></li>
</ul>

**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Brainteaser](https://leetcode.com/tag/brainteaser/)

**Similar Questions**:
* [Broken Calculator (Medium)](https://leetcode.com/problems/broken-calculator/)
* [Minimum Operations to Reduce X to Zero (Medium)](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/)

## Solution 1.

Assume we made `K` operations with $i_1, i_2, ..., i_k$, then we have 

$$a-(2^{i_1}+2^{i_2}+\cdots+2^{i_k}) - K * b = 0$$

$$a-K*b = 2^{i_1}+2^{i_2}+\cdots+2^{i_k}$$

Let `x = a - K * b`. We try `K = 1, 2, 3, ...`.

If `x` becomes negative, we should return `-1`.

Otherwise, we need to check if `x` can be expressed with `K` powers of `2`.

Say `x = 101` in binary. We can express `x` with `number of bits in x = 2` operations at minimum, and with `x = 5` operations at maximum.

So, as long as `K` is within `[{number of bits in x}, x]`, we can return this `K`.

```cpp
// OJ: https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int makeTheIntegerZero(int a, int b) {
        for (long long k = 1; true; ++k) {
            long long x = a - k * b;
            if (x <= 0) break;
            if (k >= __builtin_popcountll(x) && k <= x) return k;
        }
        return -1;
    }
};
```