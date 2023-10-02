# [371. Sum of Two Integers (Medium)](https://leetcode.com/problems/sum-of-two-integers/)

<p>Given two integers <code>a</code> and <code>b</code>, return <em>the sum of the two integers without using the operators</em> <code>+</code> <em>and</em> <code>-</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> a = 1, b = 2
<strong>Output:</strong> 3
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> a = 2, b = 3
<strong>Output:</strong> 5
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-1000 &lt;= a, b &lt;= 1000</code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Add Two Numbers (Medium)](https://leetcode.com/problems/add-two-numbers/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/sum-of-two-integers/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0, ans = 0;
        for (int i = 0; i < 32; ++i) {
            int x = (a >> i & 1), y = (b >> i & 1);
            if (carry) {
                if (x == y) {
                    ans |= 1 << i;
                    if (!x & !y) carry = 0;
                }
            } else {
                if (x != y) ans |= 1 << i;
                if (x & y) carry = 1;
            }
        }
        return ans;
    }
};
```

## Solution 2.

1. Get `carry = (a & b) << 1`, i.e. the bits that are 1s both in `a` and `b` are picked and shifted left by 1.
2. As the `11` case is handled, the rest `10`, `01`, `00` cases can be get using `a ^ b`.
3. Now the problem becomes calculating the sum of `(a & b) << 1` and `a ^ b`.
4. Go back to step 1 until there is no more `carry`.

```cpp
// OJ: https://leetcode.com/problems/sum-of-two-integers/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int carry = (a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};
```