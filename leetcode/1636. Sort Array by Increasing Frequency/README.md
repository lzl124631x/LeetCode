# [1636. Sort Array by Increasing Frequency (Easy)](https://leetcode.com/problems/sort-array-by-increasing-frequency/)

<p>Given an array of integers <code>nums</code>, sort the array in <strong>increasing</strong> order based on the frequency of the values. If multiple values have the same frequency, sort them in <strong>decreasing</strong> order.</p>

<p>Return the <em>sorted array</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,2,2,2,3]
<strong>Output:</strong> [3,1,1,2,2,2]
<strong>Explanation:</strong> '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,3,1,3,2]
<strong>Output:</strong> [1,3,3,2,2]
<strong>Explanation:</strong> '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [-1,1,-6,4,5,-6,1,4,1]
<strong>Output:</strong> [5,-1,4,4,-6,-6,1,1,1]</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sort](https://leetcode.com/tag/sort/)

**Similar Questions**:
* [Sort Characters By Frequency (Medium)](https://leetcode.com/problems/sort-characters-by-frequency/)

## Solution 1. Sort

```cpp
// OJ: https://leetcode.com/problems/sort-array-by-increasing-frequency/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> frequencySort(vector<int>& A) {
        unordered_map<int, int> cnt;
        for (int n : A) cnt[n]++;
        sort(begin(A), end(A), [&](int a, int b) { return cnt[a] != cnt[b] ? cnt[a] < cnt[b] : a > b; });
        return A;
    }
};
```