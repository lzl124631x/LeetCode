# [704. Binary Search (Easy)](https://leetcode.com/problems/binary-search/)

<p>Given a <strong>sorted</strong> (in ascending order) integer array <code>nums</code> of <code>n</code> elements and a <code>target</code> value, write a function to search <code>target</code> in <code>nums</code>. If <code>target</code> exists, then return its index, otherwise return <code>-1</code>.</p>

<p><br>
<strong>Example 1:</strong></p>

<pre><strong>Input:</strong> <code>nums</code> = [-1,0,3,5,9,12], <code>target</code> = 9
<strong>Output:</strong> 4
<strong>Explanation:</strong> 9 exists in <code>nums</code> and its index is 4

</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> <code>nums</code> = [-1,0,3,5,9,12], <code>target</code> = 2
<strong>Output:</strong> -1
<strong>Explanation:</strong> 2 does not exist in <code>nums</code> so return -1
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li>You may assume that all elements in <code>nums</code> are unique.</li>
	<li><code>n</code> will be in the range <code>[1, 10000]</code>.</li>
	<li>The value of each element in <code>nums</code> will be in the range <code>[-9999, 9999]</code>.</li>
</ol>


**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Search in a Sorted Array of Unknown Size (Medium)](https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/binary-search/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2;
            if (nums[M] > target) R = M - 1;
            else if (nums[M] < target) L = M + 1;
            else return M;
        }
        return -1;
    }
};
```