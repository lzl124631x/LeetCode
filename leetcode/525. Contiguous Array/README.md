# [525. Contiguous Array (Medium)](https://leetcode.com/problems/contiguous-array/)

<p>Given a binary array <code>nums</code>, return <em>the maximum length of a contiguous subarray with an equal number of </em><code>0</code><em> and </em><code>1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [0,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0,1,0]
<strong>Output:</strong> 2
<strong>Explanation:</strong> [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Maximum Size Subarray Sum Equals k (Medium)](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/)

## Solution 1. Prefix State Map

Replace all `0`s with `-1`s, and now the question becomes finding the longest contiguous array that sums up to 0. 

Use `unordered_map<int, int> m` to store the mapping between the running sum and the index of its first occurrence. `m` initially holds `{ 0, -1 }` which means a pseudo running sum `0` at index `-1`.

For each running sum,
* if it's the first occurrence, store the mapping -- `m[sum] = i`
* otherwise, update `ans` with `max(ans, i - m[sum])`.

```cpp
// OJ: https://leetcode.com/problems/contiguous-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://discuss.leetcode.com/topic/79906/easy-java-o-n-solution-presum-hashmap/
class Solution {
public:
    int findMaxLength(vector<int>& A) {
        unordered_map<int, int> m{{0,-1}};
        int ans = 0;
        for (int i = 0, sum = 0; i < A.size(); ++i) {
            sum += A[i] ? 1 : -1;
            if (m.count(sum)) ans = max(ans, i - m[sum]);
            else m[sum] = i;
        }
        return ans;
    }
};
```