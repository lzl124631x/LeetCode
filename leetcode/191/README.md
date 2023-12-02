# [191. Number of 1 Bits (Easy)](https://leetcode.com/problems/number-of-1-bits)

<p>Write a function that takes&nbsp;the binary representation of an unsigned integer and returns the number of &#39;1&#39; bits it has (also known as the <a href="http://en.wikipedia.org/wiki/Hamming_weight" target="_blank">Hamming weight</a>).</p>

<p><strong>Note:</strong></p>

<ul>
	<li>Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer&#39;s internal binary representation is the same, whether it is signed or unsigned.</li>
	<li>In Java, the compiler represents the signed integers using <a href="https://en.wikipedia.org/wiki/Two%27s_complement" target="_blank">2&#39;s complement notation</a>. Therefore, in <strong class="example">Example 3</strong>, the input represents the signed integer. <code>-3</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 00000000000000000000000000001011
<strong>Output:</strong> 3
<strong>Explanation:</strong> The input binary string <strong>00000000000000000000000000001011</strong> has a total of three &#39;1&#39; bits.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 00000000000000000000000010000000
<strong>Output:</strong> 1
<strong>Explanation:</strong> The input binary string <strong>00000000000000000000000010000000</strong> has a total of one &#39;1&#39; bit.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 11111111111111111111111111111101
<strong>Output:</strong> 31
<strong>Explanation:</strong> The input binary string <strong>11111111111111111111111111111101</strong> has a total of thirty one &#39;1&#39; bits.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The input must be a <strong>binary string</strong> of length <code>32</code>.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> If this function is called many times, how would you optimize it?

**Companies**:
[Apple](https://leetcode.com/company/apple), [Box](https://leetcode.com/company/box), [Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Qualcomm](https://leetcode.com/company/qualcomm), [Microsoft](https://leetcode.com/company/microsoft), [Adobe](https://leetcode.com/company/adobe), [Cisco](https://leetcode.com/company/cisco), [Bloomberg](https://leetcode.com/company/bloomberg), [Google](https://leetcode.com/company/google), [Intel](https://leetcode.com/company/intel), [Mindtickle](https://leetcode.com/company/mindtickle)

**Related Topics**:  
[Divide and Conquer](https://leetcode.com/tag/divide-and-conquer), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation)

**Similar Questions**:
* [Reverse Bits (Easy)](https://leetcode.com/problems/reverse-bits)
* [Power of Two (Easy)](https://leetcode.com/problems/power-of-two)
* [Counting Bits (Easy)](https://leetcode.com/problems/counting-bits)
* [Binary Watch (Easy)](https://leetcode.com/problems/binary-watch)
* [Hamming Distance (Easy)](https://leetcode.com/problems/hamming-distance)
* [Binary Number with Alternating Bits (Easy)](https://leetcode.com/problems/binary-number-with-alternating-bits)
* [Prime Number of Set Bits in Binary Representation (Easy)](https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation)

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
        for (; n; n -= (n & -n)) ++ans;
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/number-of-1-bits/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for (; n; n = n & (n - 1)) ++ans;
        return ans;
    }
};
```

Or `return __builtin_popcount(n);`