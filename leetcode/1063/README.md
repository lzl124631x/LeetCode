# [1063. Number of Valid Subarrays (Hard)](https://leetcode.com/problems/number-of-valid-subarrays)

<p>Given an integer array <code>nums</code>, return <em>the number of non-empty <strong>subarrays</strong> with the leftmost element of the subarray&nbsp;not larger than other elements in the subarray</em>.</p>

<p>A <strong>subarray</strong> is a <strong>contiguous</strong> part of an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,4,2,5,3]
<strong>Output:</strong> 11
<strong>Explanation:</strong> There are 11 valid subarrays: [1],[4],[2],[5],[3],[1,4],[2,5],[1,4,2],[2,5,3],[1,4,2,5],[1,4,2,5,3].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,2,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The 3 valid subarrays are: [3],[2],[1].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,2,2]
<strong>Output:</strong> 6
<strong>Explanation:</strong> There are 6 valid subarrays: [2],[2],[2],[2,2],[2,2],[2,2,2].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:
[Hulu](https://leetcode.com/company/hulu)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Stack](https://leetcode.com/tag/stack), [Monotonic Stack](https://leetcode.com/tag/monotonic-stack)

**Similar Questions**:
* [Number of Smooth Descent Periods of a Stock (Medium)](https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock)

**Hints**:
* Given a data structure that answers queries of the type to find the minimum in a range of an array (Range minimum query (RMQ) sparse table) in O(1) time. How can you solve this problem?
* For each starting index do a binary search with an RMQ to find the ending possible position.

## Solution 1.

`nextSmaller[i]` points to the next smaller element than `A[i]`.

The time complexity is `O(N)` because each `nextSmaller[i]` is visited at most once.

```cpp
// OJ: https://leetcode.com/problems/number-of-valid-subarrays
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int validSubarrays(vector<int>& A) {
        int N = A.size(), ans = 0;
        vector<int> nextSmaller(N, N);
        for (int i = N - 1; i >= 0; --i) {
            int j = i + 1;
            while (j < N && A[j] >= A[i]) j = nextSmaller[j];
            nextSmaller[i] = j;
            ans += j - i;
        }
        return ans;
    }
};
```