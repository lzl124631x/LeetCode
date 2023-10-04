# [2817. Minimum Absolute Difference Between Elements With Constraint (Medium)](https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> and an integer <code>x</code>.</p>

<p>Find the <strong>minimum absolute difference</strong> between two elements in the array that are at least <code>x</code> indices apart.</p>

<p>In other words, find two indices <code>i</code> and <code>j</code> such that <code>abs(i - j) &gt;= x</code> and <code>abs(nums[i] - nums[j])</code> is minimized.</p>

<p>Return<em> an integer denoting the <strong>minimum</strong> absolute difference between two elements that are at least</em> <code>x</code> <em>indices apart</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,3,2,4], x = 2
<strong>Output:</strong> 0
<strong>Explanation:</strong> We can select nums[0] = 4 and nums[3] = 4. 
They are at least 2 indices apart, and their absolute difference is the minimum, 0. 
It can be shown that 0 is the optimal answer.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [5,3,2,10,15], x = 1
<strong>Output:</strong> 1
<strong>Explanation:</strong> We can select nums[1] = 3 and nums[2] = 2.
They are at least 1 index apart, and their absolute difference is the minimum, 1.
It can be shown that 1 is the optimal answer.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4], x = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can select nums[0] = 1 and nums[3] = 4.
They are at least 3 indices apart, and their absolute difference is the minimum, 3.
It can be shown that 3 is the optimal answer.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= x &lt; nums.length</code></li>
</ul>


**Companies**:
[Databricks](https://leetcode.com/company/databricks), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Binary Search](https://leetcode.com/tag/binary-search), [Ordered Set](https://leetcode.com/tag/ordered-set)

**Similar Questions**:
* [K-diff Pairs in an Array (Medium)](https://leetcode.com/problems/k-diff-pairs-in-an-array)
* [Find All K-Distant Indices in an Array (Easy)](https://leetcode.com/problems/find-all-k-distant-indices-in-an-array)

**Hints**:
* <div class="_1l1MA">Let's only consider the cases where <code>i < j</code>, as the problem is symmetric.</div>
* <div class="_1l1MA">For an index <code>j</code>, we are interested in an index <code>i</code> in the range <code>[0, j - x]</code> that minimizes <code>abs(nums[i] - nums[j])</code>.</div>
* <div class="_1l1MA">For every index <code>j</code>, while going from left to right, add <code>nums[j - x]</code> to a set (C++ set, Java TreeSet, and Python sorted set).</div>
* <div class="_1l1MA">After inserting <code>nums[j - x]</code>, we can calculate the closest value to <code>nums[j]</code> in the set using binary search and store the absolute difference. In C++, we can achieve this by using lower_bound and/or upper_bound.</div>
* <div class="_1l1MA">Calculate the minimum absolute difference among all indices.</div>

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int minAbsoluteDifference(vector<int>& A, int x) {
        set<int> s;
        int ans = INT_MAX;
        for (int i = 0, N = A.size(); i < N && ans; ++i) {
            if (i - x >= 0) s.insert(A[i - x]);
            auto it = s.lower_bound(A[i]);
            if (it != s.end()) ans = min(ans, *it - A[i]);
            if (it != s.begin()) ans = min(ans, A[i] - *prev(it));
        }
        return ans;
    }
};
```