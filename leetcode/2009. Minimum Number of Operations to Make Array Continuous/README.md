# [2009. Minimum Number of Operations to Make Array Continuous (Hard)](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/)

<p>You are given an integer array <code>nums</code>. In one operation, you can replace <strong>any</strong> element in <code>nums</code> with <strong>any</strong> integer.</p>

<p><code>nums</code> is considered <strong>continuous</strong> if both of the following conditions are fulfilled:</p>

<ul>
	<li>All elements in <code>nums</code> are <strong>unique</strong>.</li>
	<li>The difference between the <strong>maximum</strong> element and the <strong>minimum</strong> element in <code>nums</code> equals <code>nums.length - 1</code>.</li>
</ul>

<p>For example, <code>nums = [4, 2, 5, 3]</code> is <strong>continuous</strong>, but <code>nums = [1, 2, 3, 5, 6]</code> is <strong>not continuous</strong>.</p>

<p>Return <em>the <strong>minimum</strong> number of operations to make </em><code>nums</code><em> </em><strong><em>continuous</em></strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [4,2,5,3]
<strong>Output:</strong> 0
<strong>Explanation:</strong>&nbsp;nums is already continuous.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,5,6]
<strong>Output:</strong> 1
<strong>Explanation:</strong>&nbsp;One possible solution is to change the last element to 4.
The resulting array is [1,2,3,5,4], which is continuous.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,10,100,1000]
<strong>Output:</strong> 3
<strong>Explanation:</strong>&nbsp;One possible solution is to:
- Change the second element to 2.
- Change the third element to 3.
- Change the fourth element to 4.
The resulting array is [1,2,3,4], which is continuous.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


**Similar Questions**:
* [Longest Repeating Character Replacement (Medium)](https://leetcode.com/problems/longest-repeating-character-replacement/)
* [Continuous Subarray Sum (Medium)](https://leetcode.com/problems/continuous-subarray-sum/)
* [Moving Stones Until Consecutive II (Medium)](https://leetcode.com/problems/moving-stones-until-consecutive-ii/)
* [Minimum One Bit Operations to Make Integers Zero (Hard)](https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/)
* [Minimum Adjacent Swaps for K Consecutive Ones (Hard)](https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/)

## Solution 1. Sliding Window

**Intuition**: Sort and only keep unique elements. The problem is the same as "get the length of the longest subarray whose difference between min and max elements is `N - 1`".

**Algorithm**:

The brute force way is to pick each `A[i]` as the start of the subarray and count the number of elements that are `<= A[i] + N - 1`, which takes `O(N^2)` time.

Since the array is already sorted, we can use sliding window so that we only traverse the entire array once.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int minOperations(vector<int>& A) {
        int N = A.size(), ans = N, j = 0;
        sort(begin(A), end(A));
        A.erase(unique(begin(A), end(A)), end(A)); // only keep unique elements
        int M = A.size();
        for (int i = 0; i < M; ++i) {
            while (j < M && A[j] <= A[i] + N - 1) ++j; // let `j` point to the first element that is out of range -- `> A[i] + N - 1`.
            ans = min(ans, N - j + i); // The length of this subarray is `j - i`. We need to replace `N - j + i` elements to make it continuous.
        }
        return ans;
    }
};
```