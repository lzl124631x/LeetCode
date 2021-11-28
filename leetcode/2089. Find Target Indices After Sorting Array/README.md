# [2089. Find Target Indices After Sorting Array (Easy)](https://leetcode.com/problems/find-target-indices-after-sorting-array/)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> and a target element <code>target</code>.</p>

<p>A <strong>target index</strong> is an index <code>i</code> such that <code>nums[i] == target</code>.</p>

<p>Return <em>a list of the target indices of</em> <code>nums</code> after<em> sorting </em><code>nums</code><em> in <strong>non-decreasing</strong> order</em>. If there are no target indices, return <em>an <strong>empty</strong> list</em>. The returned list must be sorted in <strong>increasing</strong> order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,5,2,3], target = 2
<strong>Output:</strong> [1,2]
<strong>Explanation:</strong> After sorting, nums is [1,<u><strong>2</strong></u>,<u><strong>2</strong></u>,3,5].
The indices where nums[i] == 2 are 1 and 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,5,2,3], target = 3
<strong>Output:</strong> [3]
<strong>Explanation:</strong> After sorting, nums is [1,2,2,<u><strong>3</strong></u>,5].
The index where nums[i] == 3 is 3.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,5,2,3], target = 5
<strong>Output:</strong> [4]
<strong>Explanation:</strong> After sorting, nums is [1,2,2,3,<u><strong>5</strong></u>].
The index where nums[i] == 5 is 4.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,5,2,3], target = 4
<strong>Output:</strong> []
<strong>Explanation:</strong> There are no elements in nums with value 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i], target &lt;= 100</code></li>
</ul>


**Similar Questions**:
* [Find First and Last Position of Element in Sorted Array (Medium)](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
* [Rank Transform of an Array (Easy)](https://leetcode.com/problems/rank-transform-of-an-array/)

## Solution 1. Sorting

```cpp
// OJ: https://leetcode.com/problems/find-target-indices-after-sorting-array/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1) extra space
class Solution {
public:
    vector<int> targetIndices(vector<int>& A, int target) {
        sort(begin(A), end(A));
        vector<int> ans;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == target) ans.push_back(i);
        }
        return ans;
    }
};
```

## Solution 2. Counting Sort

```cpp
// OJ: https://leetcode.com/problems/find-target-indices-after-sorting-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> targetIndices(vector<int>& A, int target) {
        int cnt = 0, rank = 0; // `cnt` is the frequency of `target`, `rank` is the sum of frequencies of all numbers < target
        for (int n : A) {
            cnt += n == target;
            rank += n < target;
        }
        vector<int> ans;
        while (cnt--) ans.push_back(rank++);
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/find-target-indices-after-sorting-array/discuss/1599800/C%2B%2B-O(N)-Time-Counting-Sort