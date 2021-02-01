# [191. Number of 1 Bits (Easy)](https://leetcode.com/problems/number-of-1-bits/)

<p>Write a function that takes an unsigned integer and returns&nbsp;the number of '1'&nbsp;bits it has (also known as the <a href="http://en.wikipedia.org/wiki/Hamming_weight" target="_blank">Hamming weight</a>).</p>

<p><strong>Note:</strong></p>

<ul>
	<li>Note that in some languages such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.</li>
	<li>In Java,&nbsp;the compiler represents the signed integers using <a href="https://en.wikipedia.org/wiki/Two%27s_complement" target="_blank">2's complement notation</a>. Therefore, in <strong>Example 3</strong>&nbsp;above, the input represents the signed integer.&nbsp;<code>-3</code>.</li>
</ul>

<p><b>Follow up</b>: If this function is called many times, how would you optimize it?</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 00000000000000000000000000001011
<strong>Output:</strong> 3
<strong>Explanation:</strong> The input binary string <strong>00000000000000000000000000001011</strong> has a total of three '1' bits.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 00000000000000000000000010000000
<strong>Output:</strong> 1
<strong>Explanation:</strong> The input binary string <strong>00000000000000000000000010000000</strong> has a total of one '1' bit.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 11111111111111111111111111111101
<strong>Output:</strong> 31
<strong>Explanation:</strong> The input binary string <strong>11111111111111111111111111111101</strong> has a total of thirty one '1' bits.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The input must be a <strong>binary string</strong> of length <code>32</code></li>
</ul>


**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Reverse Bits (Easy)](https://leetcode.com/problems/reverse-bits/)
* [Power of Two (Easy)](https://leetcode.com/problems/power-of-two/)
* [Counting Bits (Medium)](https://leetcode.com/problems/counting-bits/)
* [Binary Watch (Easy)](https://leetcode.com/problems/binary-watch/)
* [Hamming Distance (Easy)](https://leetcode.com/problems/hamming-distance/)
* [Binary Number with Alternating Bits (Easy)](https://leetcode.com/problems/binary-number-with-alternating-bits/)
* [Prime Number of Set Bits in Binary Representation (Easy)](https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-1-bits/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for (; n; n -= (n & -n), ++ans);
        return ans;
    }
};
```