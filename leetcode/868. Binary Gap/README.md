# [868. Binary Gap (Easy)](https://leetcode.com/problems/binary-gap/)

<p>Given a positive&nbsp;integer <code>N</code>, find and return the longest distance between two consecutive 1's in the binary representation of <code>N</code>.</p>

<p>If there aren't two consecutive 1's, return <font face="monospace">0</font>.</p>

<p>&nbsp;</p>

<div>
<div>
<div>
<ul>
</ul>
</div>
</div>
</div>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">22</span>
<strong>Output: </strong>2
<strong>Explanation: </strong>
22 in binary is 0b10110.
In the binary representation of 22, there are three ones, and two consecutive pairs of 1's.
The first consecutive pair of 1's have distance 2.
The second consecutive pair of 1's have distance 1.
The answer is the largest of these two distances, which is 2.
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">5</span>
<strong>Output: </strong><span id="example-output-2">2</span>
<strong>Explanation: </strong>
5 in binary is 0b101.
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">6</span>
<strong>Output: </strong><span id="example-output-3">1</span>
<strong>Explanation: </strong>
6 in binary is 0b110.
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong><span id="example-input-4-1">8</span>
<strong>Output: </strong><span id="example-output-4">0</span>
<strong>Explanation: </strong>
8 in binary is 0b1000.
There aren't any consecutive pairs of 1's in the binary representation of 8, so we return 0.
</pre>

<p>&nbsp;</p>

<div>
<div>
<div>
<p><strong>Note:</strong></p>

<ul>
	<li><code>1 &lt;= N &lt;= 10^9</code></li>
</ul>
</div>
</div>
</div>
</div>
</div>
</div>
</div>


**Companies**:  
[Twitter](https://leetcode.com/company/twitter), [eBay](https://leetcode.com/company/ebay)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/binary-gap/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int binaryGap(int N) {
        int prev = -1, i = 0, ans = 0;
        while (N) {
            if (N % 2) {
                if (prev != -1) ans = max(ans, i - prev);
                prev = i;
            }
            N /= 2;
            ++i;
        }
        return ans;
    }
};
```