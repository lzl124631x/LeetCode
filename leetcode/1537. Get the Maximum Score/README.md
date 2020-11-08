# [1537. Get the Maximum Score (Hard)](https://leetcode.com/problems/get-the-maximum-score/)

<p>You are given two <strong>sorted</strong> arrays of distinct integers <code>nums1</code> and <code>nums2.</code></p>

<p>A <strong>valid<strong><em> </em></strong>path</strong> is defined as follows:</p>

<ul>
	<li>Choose&nbsp;array nums1 or nums2 to traverse (from index-0).</li>
	<li>Traverse the current array from left to right.</li>
	<li>If you are reading any value that is present in <code>nums1</code> and <code>nums2</code>&nbsp;you are allowed to change your path to the other array. (Only one repeated value is considered in the&nbsp;valid path).</li>
</ul>

<p><em>Score</em> is defined as the sum of uniques values in a valid path.</p>

<p>Return the maximum <em>score</em> you can obtain of all possible&nbsp;<strong>valid&nbsp;paths</strong>.</p>

<p>Since the answer&nbsp;may be too large,&nbsp;return it modulo&nbsp;10^9 + 7.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/07/16/sample_1_1893.png" style="width: 538px; height: 163px;"></strong></p>

<pre><strong>Input:</strong> nums1 = [2,4,5,8,10], nums2 = [4,6,8,9]
<strong>Output:</strong> 30
<strong>Explanation:</strong>&nbsp;Valid paths:
[2,4,5,8,10], [2,4,5,8,9], [2,4,6,8,9], [2,4,6,8,10],  (starting from nums1)
[4,6,8,9], [4,5,8,10], [4,5,8,9], [4,6,8,10]    (starting from nums2)
The maximum is obtained with the path in green <strong>[2,4,6,8,10]</strong>.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,3,5,7,9], nums2 = [3,5,100]
<strong>Output:</strong> 109
<strong>Explanation:</strong>&nbsp;Maximum sum is obtained with the path <strong>[1,3,5,100]</strong>.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,2,3,4,5], nums2 = [6,7,8,9,10]
<strong>Output:</strong> 40
<strong>Explanation:</strong>&nbsp;There are no common elements between nums1 and nums2.
Maximum sum is obtained with the path [6,7,8,9,10].
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,4,5,8,9,11,19], nums2 = [2,3,4,11,12]
<strong>Output:</strong> 61
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= nums2.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 10^7</code></li>
	<li><code>nums1</code> and <code>nums2</code> are strictly increasing.</li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

**Intuition:**

If the two arrays doens't have any number in common, the result is simply `max(sum(A), sum(B))`.

So only the common numbers shared between these two arrays changes the algorithm a bit.

**Algorithm:**

Considering the subproblem with `A[0..i)]` and `B[0..j)]`: 

Let `sa` be the best score we can get if we pick `A[i]` **as the last element**.

Let `sb` be the best score we can get if we pick `B[j]` **as the last element**.

If `A[i] < B[j]`, we can only extend the `sa` by adding `A[i]` to it.

If `A[i] > B[j]`, we can only extend the `sb` by adding `B[j]` to it.

If `A[i] == B[j]`, we pick the greatest out of the following two options and set it back to `sa` and `sb`.

* extend `sa` by adding `A[i]`
* extend `sb` by adding `B[j]`

In the end, `max(sa, sb)` is the answer

```cpp
// OJ: https://leetcode.com/problems/get-the-maximum-score/
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    int maxSum(vector<int>& A, vector<int>& B) {
        long M = A.size(), N = B.size(), sa = 0, sb = 0, mod = 1e9+7, i = 0, j = 0;
        while (i < M && j < N) {
            if (A[i] < B[j]) sa += A[i++];
            else if (A[i] > B[j]) sb += B[j++];
            else sa = sb = max(sa + A[i++], sb + B[j++]);
        }
        while (i < M) sa += A[i++];
        while (j < N) sb += B[j++];
        return max(sa, sb) % mod;
    }
};
```