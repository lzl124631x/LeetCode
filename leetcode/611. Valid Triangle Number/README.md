# [611. Valid Triangle Number (Medium)](https://leetcode.com/problems/valid-triangle-number/)

<p>Given an integer array <code>nums</code>, return <em>the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,2,3,4]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [4,2,3,4]
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


**Companies**:  
[Bloomberg](https://leetcode.com/company/bloomberg), [LinkedIn](https://leetcode.com/company/linkedin), [ByteDance](https://leetcode.com/company/bytedance)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Binary Search](https://leetcode.com/tag/binary-search/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [3Sum Smaller (Medium)](https://leetcode.com/problems/3sum-smaller/)

## Solution 1. Binary Search

The naive solution is of `O(N^3)` time complexity, that is, for each triplet, detect if it can form a triangle. This solution will get TLE.

To optimize it, we first sort `nums` in ascending order. And for each pair `a` and `b`, use binary search to find the count of numbers greater than `a + b` and less than `b - a (b >= a)`.

```cpp
// OJ: https://leetcode.com/problems/valid-triangle-number
// Author: github.com/lzl124631x
// Time: O(N^2logN)
// Space: O(1)
class Solution {
public:
    int triangleNumber(vector<int>& A) {
        int N = A.size(), ans = 0;
        sort(begin(A), end(A));
        for (int i = 0; i < N; ++i) {
            int a = A[i];
            for (int j = i + 1; j < N; ++j) {
                int b = A[j];
                auto begin = upper_bound(A.begin() + j + 1, A.end(), b - a); 
                auto end = lower_bound(A.begin() + j + 1, A.end(), a + b);
                ans += max(0, (int)(end - begin));
            }
        }
        return ans;
    }
};
```