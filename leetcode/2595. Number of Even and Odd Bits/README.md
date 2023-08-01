# [2595. Number of Even and Odd Bits (Easy)](https://leetcode.com/problems/number-of-even-and-odd-bits)

<p>You are given a <strong>positive</strong> integer <code>n</code>.</p>
<p>Let <code>even</code> denote the number of even indices in the binary representation of <code>n</code> (<strong>0-indexed</strong>) with value <code>1</code>.</p>
<p>Let <code>odd</code> denote the number of odd indices in the binary representation of <code>n</code> (<strong>0-indexed</strong>) with value <code>1</code>.</p>
<p>Return <em>an integer array </em><code>answer</code><em> where </em><code>answer = [even, odd]</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> n = 17
<strong>Output:</strong> [2,0]
<strong>Explanation:</strong> The binary representation of 17 is 10001. 
It contains 1 on the 0<sup>th</sup> and 4<sup>th</sup> indices. 
There are 2 even and 0 odd indices.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> [0,1]
<strong>Explanation:</strong> The binary representation of 2 is 10.
It contains 1 on the 1<sup>st</sup> index. 
There are 0 even and 1 odd indices.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>

**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Find Numbers with Even Number of Digits (Easy)](https://leetcode.com/problems/find-numbers-with-even-number-of-digits/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-even-and-odd-bits
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2);
        for (int i = 0; n; n >>= 1, i = 1 - i) {
            ans[i] += (n & 1);
        }
        return ans;
    }
};
```