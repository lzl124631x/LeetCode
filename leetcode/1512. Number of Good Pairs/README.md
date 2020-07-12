# [1512. Number of Good Pairs (Easy)](https://leetcode.com/problems/number-of-good-pairs/)

<p>Given an array of integers&nbsp;<code>nums</code>.</p>

<p>A pair&nbsp;<code>(i,j)</code>&nbsp;is called <em>good</em> if&nbsp;<code>nums[i]</code> == <code>nums[j]</code> and <code>i</code> &lt; <code>j</code>.</p>

<p>Return the number of <em>good</em> pairs.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,1,1,3]
<strong>Output:</strong> 4
<strong>Explanation: </strong>There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,1,1]
<strong>Output:</strong> 6
<strong>Explanation: </strong>Each pair in the array are <em>good</em>.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Math](https://leetcode.com/tag/math/)

## Solution 1. Brute force

```cpp
// OJ: https://leetcode.com/problems/number-of-good-pairs/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) ans += nums[i] == nums[j];
        }
        return ans;
    }
};
```

## Solution 2. Count

```cpp
// OJ: https://leetcode.com/problems/number-of-good-pairs/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = 0;
        for (int n : nums) ans += m[n]++;
        return ans;
    }
};
```