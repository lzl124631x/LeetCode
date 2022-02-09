# [532. K-diff Pairs in an Array (Medium)](https://leetcode.com/problems/k-diff-pairs-in-an-array/)

<p>Given an array of integers <code>nums</code> and an integer <code>k</code>, return <em>the number of <b>unique</b> k-diff pairs in the array</em>.</p>

<p>A <strong>k-diff</strong> pair is an integer pair <code>(nums[i], nums[j])</code>, where the following are true:</p>

<ul>
	<li><code>0 &lt;= i &lt; j &lt; nums.length</code></li>
	<li><code>|nums[i] - nums[j]| == k</code></li>
</ul>

<p><strong>Notice</strong> that <code>|val|</code> denotes the absolute value of <code>val</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [3,1,4,1,5], k = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of <strong>unique</strong> pairs.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4,5], k = 1
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,3,1,5,4], k = 0
<strong>Output:</strong> 1
<strong>Explanation:</strong> There is one 0-diff pair in the array, (1, 1).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>7</sup> &lt;= nums[i] &lt;= 10<sup>7</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>7</sup></code></li>
</ul>


**Companies**:  
[Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Twitter](https://leetcode.com/company/twitter), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Binary Search](https://leetcode.com/tag/binary-search/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Minimum Absolute Difference in BST (Easy)](https://leetcode.com/problems/minimum-absolute-difference-in-bst/)
* [Count Number of Pairs With Absolute Difference K (Easy)](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/)
* [Kth Smallest Product of Two Sorted Arrays (Hard)](https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/)

## Solution 1. Counting

Use an `unordered_map<int, int> m` to count the occurrence of each number.

For each number `n`, we increment the answer if one of the following is true:
* `k == 0` and `m[n] > 1`.
* `k != 0` and `m[n + k] > 0`.

```cpp
// OJ: https://leetcode.com/problems/k-diff-pairs-in-an-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int findPairs(vector<int>& A, int k) {
        unordered_map<int, int> m;
        for (int n : A) m[n]++;
        int ans = 0;
        for (auto &[n, cnt] : m) {
            ans += k ? m.count(n - k) : cnt > 1;
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/k-diff-pairs-in-an-array/discuss/100101