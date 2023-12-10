# [2939. Maximum Xor Product (Medium)](https://leetcode.com/problems/maximum-xor-product)

<p>Given three integers <code>a</code>, <code>b</code>, and <code>n</code>, return <em>the <strong>maximum value</strong> of</em> <code>(a XOR x) * (b XOR x)</code> <em>where</em> <code>0 &lt;= x &lt; 2<sup>n</sup></code>.</p>

<p>Since the answer may be too large, return it <strong>modulo</strong> <code>10<sup>9 </sup>+ 7</code>.</p>

<p><strong>Note</strong> that <code>XOR</code> is the bitwise XOR operation.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> a = 12, b = 5, n = 4
<strong>Output:</strong> 98
<strong>Explanation:</strong> For x = 2, (a XOR x) = 14 and (b XOR x) = 7. Hence, (a XOR x) * (b XOR x) = 98. 
It can be shown that 98 is the maximum value of (a XOR x) * (b XOR x) for all 0 &lt;= x &lt; 2<sup>n</sup><span style="font-size: 10.8333px;">.</span>
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> a = 6, b = 7 , n = 5
<strong>Output:</strong> 930
<strong>Explanation:</strong> For x = 25, (a XOR x) = 31 and (b XOR x) = 30. Hence, (a XOR x) * (b XOR x) = 930.
It can be shown that 930 is the maximum value of (a XOR x) * (b XOR x) for all 0 &lt;= x &lt; 2<sup>n</sup>.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> a = 1, b = 6, n = 3
<strong>Output:</strong> 12
<strong>Explanation:</strong> For x = 5, (a XOR x) = 4 and (b XOR x) = 3. Hence, (a XOR x) * (b XOR x) = 12.
It can be shown that 12 is the maximum value of (a XOR x) * (b XOR x) for all 0 &lt;= x &lt; 2<sup>n</sup>.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= a, b &lt; 2<sup>50</sup></code></li>
	<li><code>0 &lt;= n &lt;= 50</code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math), [Greedy](https://leetcode.com/tag/greedy), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation)

**Similar Questions**:
* [Maximum XOR After Operations  (Medium)](https://leetcode.com/problems/maximum-xor-after-operations)

**Hints**:
* Iterate over bits from most significant to least significant.
* For the <code>i<sup>th</sup></code> bit, if both <code>a</code> and <code>b</code> have the same value, we can always make <code>x</code>’s <code>i<sup>th</sup></code> bit different from <code>a</code> and <code>b</code>, so <code>a ^ x</code> and <code>b ^ x</code> both have the <code>i<sup>th</sup></code> bit set.
* Otherwise, we can only set the <code>i<sup>th</sup></code> bit of one of <code>a ^ x</code> or <code>b ^ x</code>. Depending on the previous bits of  <code>a ^ x</code> or <code>b ^ x</code>, we should set the smaller value’s <code>i<sup>th</sup></code> bit.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-xor-product
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/maximum-xor-product/solutions/4304377/no-multiplication/
class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        int mod = 1e9 + 7;
        if (n) {
            for (long long bt = 1LL << (n - 1); bt > 0; bt >>= 1) {
                if ((min(a, b) & bt) == 0) {
                    a ^= bt;
                    b ^= bt;
                }
            }
        }
        return a % mod * (b % mod) % mod;
    }
};
```