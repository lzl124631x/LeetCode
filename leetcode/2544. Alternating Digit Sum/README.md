# [2544. Alternating Digit Sum (Easy)](https://leetcode.com/problems/alternating-digit-sum)

<p>You are given a positive integer <code>n</code>. Each digit of <code>n</code> has a sign according to the following rules:</p>
<ul>
	<li>The <strong>most significant digit</strong> is assigned a <strong>positive</strong> sign.</li>
	<li>Each other digit has an opposite sign to its adjacent digits.</li>
</ul>
<p>Return <em>the sum of all digits with their corresponding sign</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> n = 521
<strong>Output:</strong> 4
<strong>Explanation:</strong> (+5) + (-2) + (+1) = 4.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> n = 111
<strong>Output:</strong> 1
<strong>Explanation:</strong> (+1) + (-1) + (+1) = 1.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> n = 886996
<strong>Output:</strong> 0
<strong>Explanation:</strong> (+8) + (-8) + (+6) + (-9) + (+9) + (-6) = 0.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>
<p>&nbsp;</p>

**Companies**:
[eBay](https://leetcode.com/company/ebay)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Add Digits (Easy)](https://leetcode.com/problems/add-digits/)
* [Minimum Sum of Four Digit Number After Splitting Digits (Easy)](https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/)
* [Separate the Digits in an Array (Easy)](https://leetcode.com/problems/separate-the-digits-in-an-array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/alternating-digit-sum
// Author: github.com/lzl124631x
// Time: O(lgN)
// Space: O(1)
class Solution {
public:
    int alternateDigitSum(int n) {
        int ans = 0, cnt = 0;
        while (n) {
            int d = n % 10;
            ans += cnt % 2 == 0 ? d : -d;
            n /= 10;
            ++cnt;
        }
        return cnt % 2 == 0 ? -ans : ans;
    }
};
```