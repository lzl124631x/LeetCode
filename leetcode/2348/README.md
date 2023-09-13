# [2348. Number of Zero-Filled Subarrays (Medium)](https://leetcode.com/problems/number-of-zero-filled-subarrays)

<p>Given an integer array <code>nums</code>, return <em>the number of <strong>subarrays</strong> filled with </em><code>0</code>.</p>
<p>A <strong>subarray</strong> is a contiguous non-empty sequence of elements within an array.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,3,0,0,2,0,0,4]
<strong>Output:</strong> 6
<strong>Explanation:</strong> 
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [0,0,0,2,0,0]
<strong>Output:</strong> 9
<strong>Explanation:
</strong>There are 5 occurrences of [0] as a subarray.
There are 3 occurrences of [0,0] as a subarray.
There is 1 occurrence of [0,0,0] as a subarray.
There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [2,10,2019]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no subarray filled with 0. Therefore, we return 0.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Arithmetic Slices (Medium)](https://leetcode.com/problems/arithmetic-slices/)
* [Number of Smooth Descent Periods of a Stock (Medium)](https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/)
* [Length of the Longest Alphabetical Continuous Substring (Medium)](https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/)
* [Find Consecutive Integers from a Data Stream (Medium)](https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-zero-filled-subarrays
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& A) {
        long long ans = 0, N = A.size();
        for (int i = 0; i < N; ++i) {
            if (A[i] != 0) continue;
            long long cnt = 1;
            while (i + 1 < N && A[i + 1] == 0) ++i, ++cnt;
            ans += cnt * (1 + cnt) / 2;
        }
        return ans;
    }
};
```