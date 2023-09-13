# [2470. Number of Subarrays With LCM Equal to K (Medium)](https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k)

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <em>the number of <strong>subarrays</strong> of </em><code>nums</code><em> where the least common multiple of the subarray's elements is </em><code>k</code>.</p>
<p>A <strong>subarray</strong> is a contiguous non-empty sequence of elements within an array.</p>
<p>The <strong>least common multiple of an array</strong> is the smallest positive integer that is divisible by all the array elements.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [3,6,2,7,1], k = 6
<strong>Output:</strong> 4
<strong>Explanation:</strong> The subarrays of nums where 6 is the least common multiple of all the subarray's elements are:
- [<u><strong>3</strong></u>,<u><strong>6</strong></u>,2,7,1]
- [<u><strong>3</strong></u>,<u><strong>6</strong></u>,<u><strong>2</strong></u>,7,1]
- [3,<u><strong>6</strong></u>,2,7,1]
- [3,<u><strong>6</strong></u>,<u><strong>2</strong></u>,7,1]
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [3], k = 2
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no subarrays of nums where 2 is the least common multiple of all the subarray's elements.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i], k &lt;= 1000</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Number Theory](https://leetcode.com/tag/number-theory/)

**Similar Questions**:
* [Number of Subarrays With GCD Equal to K (Medium)](https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int subarrayLCM(vector<int>& A, int k) {
        int N = A.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i, c = 1; j < N && c <= k; ++j) {
                c = lcm(A[j], c);
                ans += c == k;
            }
        }
        return ans;
    }
};
```