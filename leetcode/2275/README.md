# [2275. Largest Combination With Bitwise AND Greater Than Zero (Medium)](https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero)

<p>The <strong>bitwise AND</strong> of an array <code>nums</code> is the bitwise AND of all integers in <code>nums</code>.</p>

<ul>
	<li>For example, for <code>nums = [1, 5, 3]</code>, the bitwise AND is equal to <code>1 &amp; 5 &amp; 3 = 1</code>.</li>
	<li>Also, for <code>nums = [7]</code>, the bitwise AND is <code>7</code>.</li>
</ul>

<p>You are given an array of positive integers <code>candidates</code>. Evaluate the <strong>bitwise AND</strong> of every <strong>combination</strong> of numbers of <code>candidates</code>. Each number in <code>candidates</code> may only be used <strong>once</strong> in each combination.</p>

<p>Return <em>the size of the <strong>largest</strong> combination of </em><code>candidates</code><em> with a bitwise AND <strong>greater</strong> than </em><code>0</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> candidates = [16,17,71,62,12,24,14]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The combination [16,17,62,24] has a bitwise AND of 16 &amp; 17 &amp; 62 &amp; 24 = 16 &gt; 0.
The size of the combination is 4.
It can be shown that no combination with a size greater than 4 has a bitwise AND greater than 0.
Note that more than one combination may have the largest size.
For example, the combination [62,12,24,14] has a bitwise AND of 62 &amp; 12 &amp; 24 &amp; 14 = 8 &gt; 0.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> candidates = [8,8]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The largest combination [8,8] has a bitwise AND of 8 &amp; 8 = 8 &gt; 0.
The size of the combination is 2, so we return 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= candidates.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= candidates[i] &lt;= 10<sup>7</sup></code></li>
</ul>


**Companies**:
[Adobe](https://leetcode.com/company/adobe), [Jump Trading](https://leetcode.com/company/jump-trading), [Hudson River Trading](https://leetcode.com/company/hudson-river-trading)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Hash Table](https://leetcode.com/tag/hash-table), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation), [Counting](https://leetcode.com/tag/counting)

**Similar Questions**:
* [Count Number of Maximum Bitwise-OR Subsets (Medium)](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets)

**Hints**:
* For the bitwise AND to be greater than zero, at least one bit should be 1 for every number in the combination.
* The candidates are 24 bits long, so for every bit position, we can calculate the size of the largest combination such that the bitwise AND will have a 1 at that bit position.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int largestCombination(vector<int>& A) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (int n : A) cnt += (n >> i & 1);
            ans = max(ans, cnt);
        }
        return ans;
    }
};
```