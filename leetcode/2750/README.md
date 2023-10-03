# [2750. Ways to Split Array Into Good Subarrays (Medium)](https://leetcode.com/problems/ways-to-split-array-into-good-subarrays)

<p>You are given a binary array <code>nums</code>.</p>

<p>A subarray of an array is <strong>good</strong> if it contains <strong>exactly</strong> <strong>one</strong> element with the value <code>1</code>.</p>

<p>Return <em>an integer denoting the number of ways to split the array </em><code>nums</code><em> into <strong>good</strong> subarrays</em>. As the number may be too large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>A subarray is a contiguous <strong>non-empty</strong> sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,1,0,0,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are 3 ways to split nums into good subarrays:
- [0,1] [0,0,1]
- [0,1,0] [0,1]
- [0,1,0,0] [1]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,1,0]
<strong>Output:</strong> 1
<strong>Explanation:</strong> There is 1 way to split nums into good subarrays:
- [0,1,0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Math](https://leetcode.com/tag/math), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming)

**Similar Questions**:
* [Binary Subarrays With Sum (Medium)](https://leetcode.com/problems/binary-subarrays-with-sum)
* [Count Number of Nice Subarrays (Medium)](https://leetcode.com/problems/count-number-of-nice-subarrays)

**Hints**:
* If the array consists of only 0s answer is 0.
* In the final split, exactly one separation point exists between two consecutive 1s.
* In how many ways can separation points be put?

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/ways-to-split-array-into-good-subarrays
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& A) {
        long ans = 1, mod = 1e9 + 7, N = A.size(), zero = 0, seenOne = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i] == 1) {
                if (seenOne) ans = ans * (zero + 1) % mod;
                seenOne = 1;
                zero = 0;
            } else zero++;
        }
        return seenOne ? ans : 0;
    }
};
```