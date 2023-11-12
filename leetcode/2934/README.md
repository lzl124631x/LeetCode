# [2934. Minimum Operations to Maximize Last Elements in Arrays (Medium)](https://leetcode.com/problems/minimum-operations-to-maximize-last-elements-in-arrays)

<p>You are given two <strong>0-indexed</strong> integer arrays, <code>nums1</code> and <code>nums2</code>, both having length <code>n</code>.</p>

<p>You are allowed to perform a series of <strong>operations</strong> (<strong>possibly none</strong>).</p>

<p>In an operation, you select an index <code>i</code> in the range <code>[0, n - 1]</code> and <strong>swap</strong> the values of <code>nums1[i]</code> and <code>nums2[i]</code>.</p>

<p>Your task is to find the <strong>minimum</strong> number of operations required to satisfy the following conditions:</p>

<ul>
	<li><code>nums1[n - 1]</code> is equal to the <strong>maximum value</strong> among all elements of <code>nums1</code>, i.e., <code>nums1[n - 1] = max(nums1[0], nums1[1], ..., nums1[n - 1])</code>.</li>
	<li><code>nums2[n - 1]</code> is equal to the <strong>maximum</strong> <strong>value</strong> among all elements of <code>nums2</code>, i.e., <code>nums2[n - 1] = max(nums2[0], nums2[1], ..., nums2[n - 1])</code>.</li>
</ul>

<p>Return <em>an integer denoting the <strong>minimum</strong> number of operations needed to meet <strong>both</strong> conditions</em>, <em>or </em><code>-1</code><em> if it is <strong>impossible</strong> to satisfy both conditions.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [1,2,7], nums2 = [4,5,3]
<strong>Output:</strong> 1
<strong>Explanation:</strong> In this example, an operation can be performed using index i = 2.
When nums1[2] and nums2[2] are swapped, nums1 becomes [1,2,3] and nums2 becomes [4,5,7].
Both conditions are now satisfied.
It can be shown that the minimum number of operations needed to be performed is 1.
So, the answer is 1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [2,3,4,5,9], nums2 = [8,8,4,4,4]
<strong>Output:</strong> 2
<strong>Explanation:</strong> In this example, the following operations can be performed:
First operation using index i = 4.
When nums1[4] and nums2[4] are swapped, nums1 becomes [2,3,4,5,4], and nums2 becomes [8,8,4,4,9].
Another operation using index i = 3.
When nums1[3] and nums2[3] are swapped, nums1 becomes [2,3,4,4,4], and nums2 becomes [8,8,4,5,9].
Both conditions are now satisfied.
It can be shown that the minimum number of operations needed to be performed is 2.
So, the answer is 2.   
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [1,5,4], nums2 = [2,5,3]
<strong>Output:</strong> -1
<strong>Explanation:</strong> In this example, it is not possible to satisfy both conditions. 
So, the answer is -1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n == nums1.length == nums2.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums1[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= nums2[i] &lt;= 10<sup>9</sup></code></li>
</ul>


**Similar Questions**:
* [Minimum Swaps To Make Sequences Increasing (Hard)](https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing)

**Hints**:
* Consider how to calculate the minimum number of operations when <code>nums1[n - 1]</code> and <code>nums2[n - 1]</code> are fixed (they are not swapped).
* For each index <code>i</code>, there are only <code>3</code> possibilities: <ul>
<li><code>nums1[i] <= nums1[n - 1] && nums2[i] <= nums2[n - 1]</code>. We don't need to swap them.</li>
<li><code>nums1[i] <= nums2[n - 1] && nums2[i] <= nums1[n - 1]</code>. We have to swap them.</li>
<li>Otherwise, there is no solution.</li>
</ul>
* There are <code>2</code> cases to determine the minimum number of operations: <ul>
<li>The first case is the number of indices that need to be swapped when <code>nums1[n - 1]</code> and <code>nums2[n - 1]</code> are fixed.</li>
<li>The second case is <code>1 +</code> the number of indices that need to be swapped when <code>nums1[n - 1]</code> and <code>nums2[n - 1]</code> are swapped.</li>
</ul>
* The answer is the minimum of both cases or <code>-1</code> if there is no solution in either case.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-operations-to-maximize-last-elements-in-arrays
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minOperations(vector<int>& A, vector<int>& B) {
        int N = A.size();
        auto solve = [&](vector<int> &A, vector<int> &B) -> int {
            int ans = 0;
            for (int i = 0; i < N - 1; ++i) {
                if (A[i] > A.back() || B[i] > B.back()) { // Invalid before swap
                    if (A[i] > B.back() || B[i] > A.back()) return 1e5; // Still invalid after swap
                    ++ans;
                }
            }
            return ans;
        };
        int ans = solve(A, B);
        swap(A.back(), B.back());
        ans = min(ans, 1 + solve(A, B)); // Try swapping A[n-1] and B[n-1]
        return ans >= 1e5 ? -1 : ans;
    }
};
```