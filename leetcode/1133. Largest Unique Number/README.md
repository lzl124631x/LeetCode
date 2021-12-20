# [1133. Largest Unique Number (Easy)](https://leetcode.com/problems/largest-unique-number/)

<p>Given an integer array <code>nums</code>, return <em>the largest integer that only occurs once</em>. If no integer occurs once, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [5,7,3,9,4,9,8,3,1]
<strong>Output:</strong> 8
<strong>Explanation:</strong> The maximum integer in the array is 9 but it is repeated. The number 8 occurs only once, so it is the answer.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [9,9,8,8]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is no number that occurs only once.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Sorting](https://leetcode.com/tag/sorting/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/largest-unique-number/
// Author: github.com/lzl124631x
// Time: O(N + R) where `R` is the range of the numbers
// Space: O(R) 
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        int cnt[1001] = {};
        for (int n : A) cnt[n]++;
        for (int i = 1000; i >= 0; --i) {
            if (cnt[i] == 1) return i;
        }
        return -1;
    }
};
```