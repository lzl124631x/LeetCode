# [2270. Number of Ways to Split Array (Medium)](https://leetcode.com/problems/number-of-ways-to-split-array)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> of length <code>n</code>.</p>
<p><code>nums</code> contains a <strong>valid split</strong> at index <code>i</code> if the following are true:</p>
<ul>
	<li>The sum of the first <code>i + 1</code> elements is <strong>greater than or equal to</strong> the sum of the last <code>n - i - 1</code> elements.</li>
	<li>There is <strong>at least one</strong> element to the right of <code>i</code>. That is, <code>0 &lt;= i &lt; n - 1</code>.</li>
</ul>
<p>Return <em>the number of <strong>valid splits</strong> in</em> <code>nums</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [10,4,-8,7]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
There are three ways of splitting nums into two non-empty parts:
- Split nums at index 0. Then, the first part is [10], and its sum is 10. The second part is [4,-8,7], and its sum is 3. Since 10 &gt;= 3, i = 0 is a valid split.
- Split nums at index 1. Then, the first part is [10,4], and its sum is 14. The second part is [-8,7], and its sum is -1. Since 14 &gt;= -1, i = 1 is a valid split.
- Split nums at index 2. Then, the first part is [10,4,-8], and its sum is 6. The second part is [7], and its sum is 7. Since 6 &lt; 7, i = 2 is not a valid split.
Thus, the number of valid splits in nums is 2.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [2,3,1,0]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
There are two valid splits in nums:
- Split nums at index 1. Then, the first part is [2,3], and its sum is 5. The second part is [1,0], and its sum is 1. Since 5 &gt;= 1, i = 1 is a valid split. 
- Split nums at index 2. Then, the first part is [2,3,1], and its sum is 6. The second part is [0], and its sum is 0. Since 6 &gt;= 0, i = 2 is a valid split.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Split Array Largest Sum (Hard)](https://leetcode.com/problems/split-array-largest-sum/)
* [Find Pivot Index (Easy)](https://leetcode.com/problems/find-pivot-index/)
* [Ways to Split Array Into Three Subarrays (Medium)](https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/)
* [Find the Middle Index in Array (Easy)](https://leetcode.com/problems/find-the-middle-index-in-array/)
* [Partition Array Into Two Arrays to Minimize Sum Difference (Hard)](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/)
* [Minimum Average Difference (Medium)](https://leetcode.com/problems/minimum-average-difference/)

## Solution 1. Left-to-right State Transition

```cpp
// OJ: https://leetcode.com/problems/number-of-ways-to-split-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int waysToSplitArray(vector<int>& A) {
        long right = accumulate(begin(A), end(A), 0L), left = 0, ans = 0, N = A.size();
        for (int i = 0; i < N - 1; ++i) {
            left += A[i];
            right -= A[i];
            ans += left >= right;
        }
        return ans;
    }
};
```