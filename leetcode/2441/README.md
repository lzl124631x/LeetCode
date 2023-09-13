# [2441. Largest Positive Integer That Exists With Its Negative (Easy)](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative)

<p>Given an integer array <code>nums</code> that <strong>does not contain</strong> any zeros, find <strong>the largest positive</strong> integer <code>k</code> such that <code>-k</code> also exists in the array.</p>
<p>Return <em>the positive integer </em><code>k</code>. If there is no such integer, return <code>-1</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [-1,2,-3,3]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 3 is the only valid k we can find in the array.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [-1,10,6,7,-7,1]
<strong>Output:</strong> 7
<strong>Explanation:</strong> Both 1 and 7 have their corresponding negative values in the array. 7 has a larger value.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [-10,8,6,7,-2,-3]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is no a single valid k, we return -1.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-1000 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>nums[i] != 0</code></li>
</ul>

**Companies**:
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int findMaxK(vector<int>& A) {
        sort(begin(A), end(A));
        for (int i = 0, j = A.size() - 1; i < j && A[i] < 0 && A[j] > 0;) {
            if (-A[i] == A[j]) return A[j];
            if (-A[i] > A[j]) ++i;
            else --j;
        }
        return -1;
    }
};
```

We can have `O(N)` time `O(D)` space with counting sort.