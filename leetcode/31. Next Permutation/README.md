# [31. Next Permutation (Medium)](https://leetcode.com/problems/next-permutation)

<p>A <strong>permutation</strong> of an array of integers is an arrangement of its members into a sequence or linear order.</p>
<ul>
	<li>For example, for <code>arr = [1,2,3]</code>, the following are all the permutations of <code>arr</code>: <code>[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1]</code>.</li>
</ul>
<p>The <strong>next permutation</strong> of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the <strong>next permutation</strong> of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).</p>
<ul>
	<li>For example, the next permutation of <code>arr = [1,2,3]</code> is <code>[1,3,2]</code>.</li>
	<li>Similarly, the next permutation of <code>arr = [2,3,1]</code> is <code>[3,1,2]</code>.</li>
	<li>While the next permutation of <code>arr = [3,2,1]</code> is <code>[1,2,3]</code> because <code>[3,2,1]</code> does not have a lexicographical larger rearrangement.</li>
</ul>
<p>Given an array of integers <code>nums</code>, <em>find the next permutation of</em> <code>nums</code>.</p>
<p>The replacement must be <strong><a href="http://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in place</a></strong> and use only constant extra memory.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [1,3,2]
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [3,2,1]
<strong>Output:</strong> [1,2,3]
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [1,1,5]
<strong>Output:</strong> [1,5,1]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 100</code></li>
</ul>

**Companies**:
[JPMorgan](https://leetcode.com/company/jpmorgan), [Amazon](https://leetcode.com/company/amazon), [Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Permutations (Medium)](https://leetcode.com/problems/permutations/)
* [Permutations II (Medium)](https://leetcode.com/problems/permutations-ii/)
* [Permutation Sequence (Hard)](https://leetcode.com/problems/permutation-sequence/)
* [Palindrome Permutation II (Medium)](https://leetcode.com/problems/palindrome-permutation-ii/)
* [Minimum Adjacent Swaps to Reach the Kth Smallest Number (Medium)](https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/next-permutation
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int N = A.size(), i = N - 1;
        while (i - 1 >= 0 && A[i - 1] >= A[i]) --i; // find the first element of a descending subarray from the end.
        reverse(begin(A) + i, end(A)); // reverse this descending subarray
        if (i - 1 >= 0) swap(*upper_bound(begin(A) + i, end(A), A[i - 1]), A[i - 1]); // swap A[i-1] with the first element greater than `A[i-1]` in the subarray.
    }
};
```