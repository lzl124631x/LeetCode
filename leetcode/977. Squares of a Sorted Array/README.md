# [977. Squares of a Sorted Array (Easy)](https://leetcode.com/problems/squares-of-a-sorted-array/)

<p>Given an integer array <code>nums</code> sorted in <strong>non-decreasing</strong> order, return <em>an array of <strong>the squares of each number</strong> sorted in non-decreasing order</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [-4,-1,0,3,10]
<strong>Output:</strong> [0,1,9,16,100]
<strong>Explanation:</strong> After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [-7,-3,2,3,11]
<strong>Output:</strong> [4,9,9,49,121]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code><span>1 &lt;= nums.length &lt;= </span>10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> is sorted in <strong>non-decreasing</strong> order.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Squaring each element and sorting the new array is very trivial, could you find an <code>O(n)</code> solution using a different approach?

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Merge Sorted Array (Easy)](https://leetcode.com/problems/merge-sorted-array/)
* [Sort Transformed Array (Medium)](https://leetcode.com/problems/sort-transformed-array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/squares-of-a-sorted-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int N = A.size();
        for (int &n : A) n *= n;
        vector<int> ans(N);
        for (int i = 0, j = N - 1, k = N - 1; i <= j; ) {
            if (A[i] > A[j] ) {
                ans[k--] = A[i];
                ++i;
            } else {
                ans[k--] = A[j];
                --j;
            }
        }
        return ans;
    }
};
```