# [982. Triples with Bitwise AND Equal To Zero (Hard)](https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/)

<p>Given an integer array nums, return <em>the number of <strong>AND triples</strong></em>.</p>

<p>An <strong>AND triple</strong> is a triple of indices <code>(i, j, k)</code> such that:</p>

<ul>
	<li><code>0 &lt;= i &lt; nums.length</code></li>
	<li><code>0 &lt;= j &lt; nums.length</code></li>
	<li><code>0 &lt;= k &lt; nums.length</code></li>
	<li><code>nums[i] &amp; nums[j] &amp; nums[k] == 0</code>, where <code>&amp;</code> represents the bitwise-AND operator.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,1,3]
<strong>Output:</strong> 12
<strong>Explanation:</strong> We could choose the following i, j, k triples:
(i=0, j=0, k=1) : 2 &amp; 2 &amp; 1
(i=0, j=1, k=0) : 2 &amp; 1 &amp; 2
(i=0, j=1, k=1) : 2 &amp; 1 &amp; 1
(i=0, j=1, k=2) : 2 &amp; 1 &amp; 3
(i=0, j=2, k=1) : 2 &amp; 3 &amp; 1
(i=1, j=0, k=0) : 1 &amp; 2 &amp; 2
(i=1, j=0, k=1) : 1 &amp; 2 &amp; 1
(i=1, j=0, k=2) : 1 &amp; 2 &amp; 3
(i=1, j=1, k=0) : 1 &amp; 1 &amp; 2
(i=1, j=2, k=0) : 1 &amp; 3 &amp; 2
(i=2, j=0, k=1) : 3 &amp; 2 &amp; 1
(i=2, j=1, k=0) : 3 &amp; 1 &amp; 2
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0,0,0]
<strong>Output:</strong> 27
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt; 2<sup>16</sup></code></li>
</ul>


**Companies**:  
[Flipkart](https://leetcode.com/company/flipkart)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1. 

Let's say a triple is `a, b, c`. It takes `O(N^2)` time to enumerate all the `a, b` pairs, but there will be only `2^16` numbers of `a & b` values. Since at worst `N^2 = 1e6` and `2^16 = 65536 = 6e4`, encoding the `O(N^2)` data into a `O(2^16)` data by counting different `a & b` values can save time.

So we first count different `a & b` values using `O(N^2)` time and `O(M) = O(2^16)` space, then enumerate all `a & b` and `c` pairs using `O(MN)` time.

```cpp
// OJ: https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/
// Author: github.com/lzl124631x
// Time: O(N^2 + NM) where `N` is the length of `A`, and `M` is the range of values in `A`.
// Space: O(M)
class Solution {
public:
    int countTriplets(vector<int> &A) {
        int cnt[1 << 16] = {}, ans = 0;
        for (int a : A) {
            for (int b : A) ++cnt[a & b];
        }
        for (int n : A) {
            for (int i = 0; i < (1 << 16); ++i) {
                if ((i & n) == 0) ans += cnt[i];
            }
        }
        return ans;
    }
};
```