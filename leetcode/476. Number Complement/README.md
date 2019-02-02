# [476. Number Complement (Easy)](https://leetcode.com/problems/number-complement/)

<p>Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.</p>

<p><b>Note:</b><br>
</p><ol>
<li>The given integer is guaranteed to fit within the range of a 32-bit signed integer.</li>
<li>You could assume no leading zero bit in the integer’s binary representation.</li>
</ol>
<p></p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> 5
<b>Output:</b> 2
<b>Explanation:</b> The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> 1
<b>Output:</b> 0
<b>Explanation:</b> The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
</pre>
<p></p>

**Companies**:  
[Cloudera](https://leetcode.com/company/cloudera)

**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1.

For example:

```
num          = 00000101
mask         = 11111000
~mask & ~num = 00000010
```

```cpp
// OJ: https://leetcode.com/problems/number-complement/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while (num & mask) mask <<= 1;
        return ~mask & ~num;
    }
};
```