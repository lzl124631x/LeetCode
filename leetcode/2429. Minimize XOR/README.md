# [2429. Minimize XOR (Medium)](https://leetcode.com/problems/minimize-xor)

<p>Given two positive integers <code>num1</code> and <code>num2</code>, find the positive integer <code>x</code> such that:</p>
<ul>
	<li><code>x</code> has the same number of set bits as <code>num2</code>, and</li>
	<li>The value <code>x XOR num1</code> is <strong>minimal</strong>.</li>
</ul>
<p>Note that <code>XOR</code> is the bitwise XOR operation.</p>
<p>Return <em>the integer </em><code>x</code>. The test cases are generated such that <code>x</code> is <strong>uniquely determined</strong>.</p>
<p>The number of <strong>set bits</strong> of an integer is the number of <code>1</code>'s in its binary representation.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> num1 = 3, num2 = 5
<strong>Output:</strong> 3
<strong>Explanation:</strong>
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer <strong>3</strong> has the same number of set bits as num2, and the value <code>3 XOR 3 = 0</code> is minimal.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> num1 = 1, num2 = 12
<strong>Output:</strong> 3
<strong>Explanation:</strong>
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer <strong>3</strong> has the same number of set bits as num2, and the value <code>3 XOR 1 = 2</code> is minimal.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= num1, num2 &lt;= 10<sup>9</sup></code></li>
</ul>

**Companies**:
[Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Maximum XOR of Two Numbers in an Array (Medium)](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/)
* [Maximum XOR With an Element From Array (Hard)](https://leetcode.com/problems/maximum-xor-with-an-element-from-array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimize-xor
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int minimizeXor(int a, int b) {
        int ca = __builtin_popcount(a), cb = __builtin_popcount(b);
        if (ca == cb) return a;
        if (ca < cb) { // start from a, add missing 1s from the right
            int ans = a;
            cb -= ca;
            for (int i = 0; i < 32 && cb; ++i) {
                if (ans >> i & 1) continue;
                ans |= 1 << i;
                --cb;
            }
            return ans;
        }
        // start from 0, add 1s from the right of a
        int ans = 0;
        for (int i = 31; i >= 0 && cb; --i) {
            if (a >> i & 1) {
                ans |= 1 << i;
                --cb;
            }
        }
        return ans;
    }
};
```