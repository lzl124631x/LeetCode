# [1012. Complement of Base 10 Integer (Easy)](https://leetcode.com/problems/complement-of-base-10-integer/)

<p>Every non-negative integer <code>N</code>&nbsp;has a binary representation.&nbsp; For example,&nbsp;<code>5</code> can be represented as <code>"101"</code>&nbsp;in binary, <code>11</code> as <code>"1011"</code>&nbsp;in binary, and so on.&nbsp; Note that except for <code>N = 0</code>, there are no leading zeroes in any&nbsp;binary representation.</p>

<p>The <em>complement</em>&nbsp;of a binary representation&nbsp;is the number in binary you get when changing every <code>1</code> to a <code>0</code> and <code>0</code> to a <code>1</code>.&nbsp; For example, the complement of <code>"101"</code> in binary is <code>"010"</code> in binary.</p>

<p>For a given number <code>N</code> in base-10, return the complement of it's binary representation as a&nbsp;base-10 integer.</p>

<p>&nbsp;</p>

<ol>
</ol>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">5</span>
<strong>Output: </strong><span id="example-output-1">2</span>
<strong>Explanation: </strong>5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">7</span>
<strong>Output: </strong><span id="example-output-2">0</span>
<span id="example-output-1"><strong>Explanation: </strong>7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.
</span></pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">10</span>
<strong>Output: </strong><span id="example-output-3">5</span>
<strong>Explanation: </strong>10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>0 &lt;= N &lt; 10^9</code></li>
</ol>
</div>
</div>
</div>

**Companies**:  
[Cloudera](https://leetcode.com/company/cloudera)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/complement-of-base-10-integer/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int bitwiseComplement(int N) {
        if (!N) return 1;
        unsigned mask = ~0;
        while (mask & N) mask <<= 1;
        return ~N & ~mask;
    }
};
```