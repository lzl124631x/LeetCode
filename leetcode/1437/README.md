# [1437. Check If All 1's Are at Least Length K Places Away (Medium)](https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/)

<p>Given an array <code>nums</code> of 0s and 1s and an integer <code>k</code>, return <code>True</code> if all 1's are at least <code>k</code> places away from each other, otherwise return <code>False</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/04/15/sample_1_1791.png" style="width: 214px; height: 90px;"></strong></p>

<pre><strong>Input:</strong> nums = [1,0,0,0,1,0,0,1], k = 2
<strong>Output:</strong> true
<strong>Explanation:</strong> Each of the 1s are at least 2 places away from each other.
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/04/15/sample_2_1791.png" style="width: 160px; height: 86px;"></strong></p>

<pre><strong>Input:</strong> nums = [1,0,0,1,0,1], k = 2
<strong>Output:</strong> false
<strong>Explanation: </strong>The second 1 and third 1 are only one apart from each other.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,1,1,1], k = 0
<strong>Output:</strong> true
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> nums = [0,1,0,1], k = 1
<strong>Output:</strong> true
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= k &lt;= nums.length</code></li>
	<li><code>nums[i]</code>&nbsp;is&nbsp;<code>0</code>&nbsp;or&nbsp;<code>1</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool kLengthApart(vector<int>& A, int k) {
        int prev = -k - 1;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == 0) continue;
            if (i - prev <= k) return false;  
            prev = i;
        }
        return true;
    }
};
```