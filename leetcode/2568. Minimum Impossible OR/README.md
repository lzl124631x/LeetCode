# [2568. Minimum Impossible OR (Medium)](https://leetcode.com/problems/minimum-impossible-or)

<p>You are given a <strong>0-indexed</strong>&nbsp;integer array <code>nums</code>.</p>
<p>We say that an integer x is <strong>expressible</strong> from <code>nums</code> if there exist some integers <code>0 &lt;= index<sub>1</sub> &lt; index<sub>2</sub> &lt; ... &lt; index<sub>k</sub> &lt; nums.length</code> for which <code>nums[index<sub>1</sub>] | nums[index<sub>2</sub>] | ... | nums[index<sub>k</sub>] = x</code>. In other words, an integer is expressible if it can be written as the bitwise OR of some subsequence of <code>nums</code>.</p>
<p>Return <em>the minimum <strong>positive non-zero integer</strong>&nbsp;that is not </em><em>expressible from </em><code>nums</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [2,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 1 and 2 are already present in the array. We know that 3 is expressible, since nums[0] | nums[1] = 2 | 1 = 3. Since 4 is not expressible, we return 4.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [5,3,2]
<strong>Output:</strong> 1
<strong>Explanation:</strong> We can show that 1 is the smallest number that is not expressible.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Brainteaser](https://leetcode.com/tag/brainteaser/)

## Solution 1.

We can find that powers of `2` are hard to get using OR.

If we have `1,2,4`, we can get all numbers with 3 bits. The next impossible number is `8`.

If we have `1,3,4`, we can't get `2`.

So, the minimum impossible number we can't get is the smallest power of 2 that doesn't exist in `A`.

```cpp
// OJ: https://leetcode.com/problems/minimum-impossible-or
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int minImpossibleOR(vector<int>& A) {
        int seen = 0;
        for (int i : A) {
            if ((i & (i - 1)) == 0) seen |= i;
        }
        for (int i = 0; i < 32; ++i) {
            if ((seen >> i & 1) == 0) return 1 << i;
        }
        return -1;
    }
};
```