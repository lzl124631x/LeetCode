# [2221. Find Triangular Sum of an Array (Medium)](https://leetcode.com/problems/find-triangular-sum-of-an-array/)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>, where <code>nums[i]</code> is a digit between <code>0</code> and <code>9</code> (<strong>inclusive</strong>).</p>

<p>The <strong>triangular sum</strong> of <code>nums</code> is the value of the only element present in <code>nums</code> after the following process terminates:</p>

<ol>
	<li>Let <code>nums</code> comprise of <code>n</code> elements. If <code>n == 1</code>, <strong>end</strong> the process. Otherwise, <strong>create</strong> a new <strong>0-indexed</strong> integer array <code>newNums</code> of length <code>n - 1</code>.</li>
	<li>For each index <code>i</code>, where <code>0 &lt;= i &lt;&nbsp;n - 1</code>, <strong>assign</strong> the value of <code>newNums[i]</code> as <code>(nums[i] + nums[i+1]) % 10</code>, where <code>%</code> denotes modulo operator.</li>
	<li><strong>Replace</strong> the array <code>nums</code> with <code>newNums</code>.</li>
	<li><strong>Repeat</strong> the entire process starting from step 1.</li>
</ol>

<p>Return <em>the triangular sum of</em> <code>nums</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/02/22/ex1drawio.png" style="width: 250px; height: 250px;">
<pre><strong>Input:</strong> nums = [1,2,3,4,5]
<strong>Output:</strong> 8
<strong>Explanation:</strong>
The above diagram depicts the process from which we obtain the triangular sum of the array.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [5]
<strong>Output:</strong> 5
<strong>Explanation:</strong>
Since there is only one element in nums, the triangular sum is the value of that element itself.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 9</code></li>
</ul>


**Similar Questions**:
* [Pascal's Triangle II (Easy)](https://leetcode.com/problems/pascals-triangle-ii/)

## Solution 1. Pascal's Triangle

```cpp
// OJ: https://leetcode.com/problems/find-triangular-sum-of-an-array/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1) extra space
class Solution {
public:
    int triangularSum(vector<int>& A) {
        for (int i = A.size(); i >= 1; --i) {
            for (int j = 0; j < i - 1; ++j) {
                A[j] = (A[j] + A[j + 1]) % 10;
            }
        }
        return A[0];
    }
};
```

## Discuss

https://leetcode.com/problems/find-triangular-sum-of-an-array/discuss/1907038/