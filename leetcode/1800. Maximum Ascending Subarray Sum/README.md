# [1800. Maximum Ascending Subarray Sum (Easy)](https://leetcode.com/problems/maximum-ascending-subarray-sum/)

<p>Given an array of positive integers <code>nums</code>, return the <em>maximum possible sum of an <strong>ascending</strong> subarray in </em><code>nums</code>.</p>

<p>A subarray is defined as a contiguous sequence of numbers in an array.</p>

<p>A subarray <code>[nums<sub>l</sub>, nums<sub>l+1</sub>, ..., nums<sub>r-1</sub>, nums<sub>r</sub>]</code> is <strong>ascending</strong> if for all <code>i</code> where <code>l &lt;= i &lt; r</code>, <code>nums<sub>i </sub> &lt; nums<sub>i+1</sub></code>. Note that a subarray of size <code>1</code> is <strong>ascending</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [10,20,30,5,10,50]
<strong>Output:</strong> 65
<strong>Explanation: </strong>[5,10,50] is the ascending subarray with the maximum sum of 65.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [10,20,30,40,50]
<strong>Output:</strong> 150
<strong>Explanation: </strong>[10,20,30,40,50] is the ascending subarray with the maximum sum of 150.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [12,17,15,13,10,11,12]
<strong>Output:</strong> 33
<strong>Explanation: </strong>[10,11,12] is the ascending subarray with the maximum sum of 33.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> nums = [100,10,1]
<strong>Output:</strong> 100
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-ascending-subarray-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxAscendingSum(vector<int>& A) {
        int ans = A[0], sum = A[0];
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] > A[i - 1]) {
                sum += A[i];
            } else {
                sum = A[i];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
```