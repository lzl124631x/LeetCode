# [2447. Number of Subarrays With GCD Equal to K (Medium)](https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k)

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <em>the number of <strong>subarrays</strong> of </em><code>nums</code><em> where the greatest common divisor of the subarray&#39;s elements is </em><code>k</code>.</p>

<p>A <strong>subarray</strong> is a contiguous non-empty sequence of elements within an array.</p>

<p>The <strong>greatest common divisor of an array</strong> is the largest integer that evenly divides all the array elements.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [9,3,1,2,6,3], k = 3
<strong>Output:</strong> 4
<strong>Explanation:</strong> The subarrays of nums where 3 is the greatest common divisor of all the subarray&#39;s elements are:
- [9,<u><strong>3</strong></u>,1,2,6,3]
- [9,3,1,2,6,<u><strong>3</strong></u>]
- [<u><strong>9,3</strong></u>,1,2,6,3]
- [9,3,1,2,<u><strong>6,3</strong></u>]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [4], k = 7
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no subarrays of nums where 7 is the greatest common divisor of all the subarray&#39;s elements.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i], k &lt;= 10<sup>9</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Math](https://leetcode.com/tag/math), [Number Theory](https://leetcode.com/tag/number-theory)

**Similar Questions**:
* [Find Greatest Common Divisor of Array (Easy)](https://leetcode.com/problems/find-greatest-common-divisor-of-array)
* [Number of Subarrays With LCM Equal to K (Medium)](https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int subarrayGCD(vector<int>& A, int k) {
        int N = A.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            int d = A[i];
            for (int j = i; j < N; ++j) {
                d = gcd(d, A[j]);
                if (gcd(d, k) < k) break;
                ans += d == k;
            }
        }
        return ans;
    }
};
```