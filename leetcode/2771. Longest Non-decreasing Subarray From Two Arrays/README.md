# [2771. Longest Non-decreasing Subarray From Two Arrays (Medium)](https://leetcode.com/problems/longest-non-decreasing-subarray-from-two-arrays)

<p>You are given two <strong>0-indexed</strong> integer arrays <code>nums1</code> and <code>nums2</code> of length <code>n</code>.</p>
<p>Let's define another <strong>0-indexed</strong> integer array, <code>nums3</code>, of length <code>n</code>. For each index <code>i</code> in the range <code>[0, n - 1]</code>, you can assign either <code>nums1[i]</code> or <code>nums2[i]</code> to <code>nums3[i]</code>.</p>
<p>Your task is to maximize the length of the <strong>longest non-decreasing subarray</strong> in <code>nums3</code> by choosing its values optimally.</p>
<p>Return <em>an integer representing the length of the <strong>longest non-decreasing</strong> subarray in</em> <code>nums3</code>.</p>
<p><strong>Note: </strong>A <strong>subarray</strong> is a contiguous <strong>non-empty</strong> sequence of elements within an array.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums1 = [2,3,1], nums2 = [1,2,1]
<strong>Output:</strong> 2
<strong>Explanation: </strong>One way to construct nums3 is: 
nums3 = [nums1[0], nums2[1], nums2[2]] =&gt; [2,2,1]. 
The subarray starting from index 0 and ending at index 1, [2,2], forms a non-decreasing subarray of length 2. 
We can show that 2 is the maximum achievable length.</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums1 = [1,3,2,1], nums2 = [2,2,3,4]
<strong>Output:</strong> 4
<strong>Explanation:</strong> One way to construct nums3 is: 
nums3 = [nums1[0], nums2[1], nums2[2], nums2[3]] =&gt; [1,2,3,4]. 
The entire array forms a non-decreasing subarray of length 4, making it the maximum achievable length.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums1 = [1,1], nums2 = [2,2]
<strong>Output:</strong> 2
<strong>Explanation:</strong> One way to construct nums3 is: 
nums3 = [nums1[0], nums1[1]] =&gt; [1,1]. 
The entire array forms a non-decreasing subarray of length 2, making it the maximum achievable length.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums1.length == nums2.length == n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 10<sup>9</sup></code></li>
</ul>

**Companies**:
[Polar](https://leetcode.com/company/polar)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Russian Doll Envelopes (Hard)](https://leetcode.com/problems/russian-doll-envelopes/)
* [Maximum Length of Pair Chain (Medium)](https://leetcode.com/problems/maximum-length-of-pair-chain/)

## Solution 1.

Let `dp[i][j]` be the length of the longest subarray of `A[0..i]` ending with `X[i][j]`, where `X[i][0] = A[i]` and `X[i][1] = B[i]`.

```
dp[i][j] = 1 + max( dp[i-1][k] | X[i][j] >= X[i-1][k] )
```

The answer is the maximum of `dp[i][j]`.


```cpp
// OJ: https://leetcode.com/problems/longest-non-decreasing-subarray-from-two-arrays
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxNonDecreasingLength(vector<int>& A, vector<int>& B) {
        int N = A.size(), ans = 1;
        vector<vector<int>> dp(N, vector<int>(2, 1));
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j <= 1; ++j) {
                int a = j == 0 ? A[i] : B[i];
                for (int k = 0; k <= 1; ++k) {
                    int b = k == 0 ? A[i - 1] : B[i - 1];
                    if (a >= b) dp[i][j] = max(dp[i][j], 1 + dp[i - 1][k]);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
```