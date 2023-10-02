# [2574. Left and Right Sum Differences (Easy)](https://leetcode.com/problems/left-and-right-sum-differences)

<p>Given a <strong>0-indexed</strong> integer array <code>nums</code>, find a <strong>0-indexed </strong>integer array <code>answer</code> where:</p>

<ul>
    <li><code>answer.length == nums.length</code>.</li>
    <li><code>answer[i] = |leftSum[i] - rightSum[i]|</code>.</li>
</ul>

<p>Where:</p>

<ul>
    <li><code>leftSum[i]</code> is the sum of elements to the left of the index <code>i</code> in the array <code>nums</code>. If there is no such element, <code>leftSum[i] = 0</code>.</li>
    <li><code>rightSum[i]</code> is the sum of elements to the right of the index <code>i</code> in the array <code>nums</code>. If there is no such element, <code>rightSum[i] = 0</code>.</li>
</ul>

<p>Return <em>the array</em> <code>answer</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [10,4,8,3]
<strong>Output:</strong> [15,1,11,22]
<strong>Explanation:</strong> The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1]
<strong>Output:</strong> [0]
<strong>Explanation:</strong> The array leftSum is [0] and the array rightSum is [0].
The array answer is [|0 - 0|] = [0].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Find Pivot Index (Easy)](https://leetcode.com/problems/find-pivot-index/)
* [Find the Middle Index in Array (Easy)](https://leetcode.com/problems/find-the-middle-index-in-array/)
* [Find the Distinct Difference Array (Easy)](https://leetcode.com/problems/find-the-distinct-difference-array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/left-and-right-sum-differences
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& A) {
        int N = A.size();
        vector<int> leftSum(N), rightSum(N);
        for (int i = 1; i < N; ++i) {
            leftSum[i] = leftSum[i - 1] + A[i - 1];
            rightSum[N - i - 1] = rightSum[N - i] + A[N - i];
        }
        for (int i = 0; i < N; ++i) A[i] = abs(leftSum[i] - rightSum[i]);
        return A;
    }
};
```