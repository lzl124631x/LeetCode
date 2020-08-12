# [154. Find Minimum in Rotated Sorted Array II (Hard)](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)

<p>Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.</p>

<p>(i.e., &nbsp;<code>[0,1,2,4,5,6,7]</code>&nbsp;might become &nbsp;<code>[4,5,6,7,0,1,2]</code>).</p>

<p>Find the minimum element.</p>

<p>The array may contain duplicates.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [1,3,5]
<strong>Output:</strong> 1</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [2,2,2,0,1]
<strong>Output:</strong> 0</pre>

<p><strong>Note:</strong></p>

<ul>
	<li>This is a follow up problem to&nbsp;<a href="https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/">Find Minimum in Rotated Sorted Array</a>.</li>
	<li>Would allow duplicates affect the run-time complexity? How and why?</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Find Minimum in Rotated Sorted Array (Medium)](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Author: github.com/lzl124631x
// Time: average O(N), worst O(logN)
// Space: O(1)
class Solution {
public:
    int findMin(vector<int>& A) {
        int L = 0, R = A.size() - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if (A[M] > A[R]) L = M + 1;
            else if (A[M] < A[R]) R = M;
            else --R; // since `A[L]` might be the answer and `A[M]` is the same as `A[R]`, it's safe to --R.
        }
        return A[L];
    }
};
```