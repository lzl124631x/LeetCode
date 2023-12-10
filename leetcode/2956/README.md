# [2956. Find Common Elements Between Two Arrays (Easy)](https://leetcode.com/problems/find-common-elements-between-two-arrays)

<p>You are given two <strong>0-indexed</strong> integer arrays <code>nums1</code> and <code>nums2</code> of sizes <code>n</code> and <code>m</code>, respectively.</p>

<p>Consider calculating the following values:</p>

<ul>
	<li>The number of indices <code>i</code> such that <code>0 &lt;= i &lt; n</code> and <code>nums1[i]</code> occurs <strong>at least</strong> once in <code>nums2</code>.</li>
	<li>The number of indices <code>i</code> such that <code>0 &lt;= i &lt; m</code> and <code>nums2[i]</code> occurs <strong>at least</strong> once in <code>nums1</code>.</li>
</ul>

<p>Return <em>an integer array </em><code>answer</code><em> of size </em><code>2</code><em> containing the two values <strong>in the above order</strong></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [4,3,2,3,1], nums2 = [2,2,5,2,3,6]
<strong>Output:</strong> [3,4]
<strong>Explanation:</strong> We calculate the values as follows:
- The elements at indices 1, 2, and 3 in nums1 occur at least once in nums2. So the first value is 3.
- The elements at indices 0, 1, 3, and 4 in nums2 occur at least once in nums1. So the second value is 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [3,4,2,3], nums2 = [1,5]
<strong>Output:</strong> [0,0]
<strong>Explanation:</strong> There are no common elements between the two arrays, so the two values will be 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums1.length</code></li>
	<li><code>m == nums2.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 100</code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 100</code></li>
</ul>


**Hints**:
* Since the constraints are small, you can use brute force to solve the problem.
* For each element <code>i</code> in <code>nums1</code>, iterate over all elements of <code>nums2</code> to find if it occurs.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-common-elements-between-two-arrays
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& A, vector<int>& B) {
        unordered_set<int> a(begin(A), end(A)), b(begin(B), end(B));
        vector<int> ans(2);
        for (int n : A) ans[0] += b.count(n);
        for (int n : B) ans[1] += a.count(n);
        return ans;
    }
};
```