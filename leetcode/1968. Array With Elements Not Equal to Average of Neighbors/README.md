# [1968. Array With Elements Not Equal to Average of Neighbors (Medium)](https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/)

<p>You are given a <strong>0-indexed</strong> array <code>nums</code> of <strong>distinct</strong> integers. You want to rearrange the elements in the array such that every element in the rearranged array is <strong>not</strong> equal to the <strong>average</strong> of its neighbors.</p>

<p>More formally, the rearranged array should have the property such that for every <code>i</code> in the range <code>1 &lt;= i &lt; nums.length - 1</code>, <code>(nums[i-1] + nums[i+1]) / 2</code> is <strong>not</strong> equal to <code>nums[i]</code>.</p>

<p>Return <em><strong>any</strong> rearrangement of </em><code>nums</code><em> that meets the requirements</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4,5]
<strong>Output:</strong> [1,2,4,5,3]
<strong>Explanation:</strong>
When i=1, nums[i] = 2, and the average of its neighbors is (1+4) / 2 = 2.5.
When i=2, nums[i] = 4, and the average of its neighbors is (2+5) / 2 = 3.5.
When i=3, nums[i] = 5, and the average of its neighbors is (4+3) / 2 = 3.5.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [6,2,0,9,7]
<strong>Output:</strong> [9,7,6,2,0]
<strong>Explanation:</strong>
When i=1, nums[i] = 7, and the average of its neighbors is (9+6) / 2 = 7.5.
When i=2, nums[i] = 6, and the average of its neighbors is (7+2) / 2 = 4.5.
When i=3, nums[i] = 2, and the average of its neighbors is (6+0) / 2 = 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Similar Questions**:
* [Wiggle Sort (Medium)](https://leetcode.com/problems/wiggle-sort/)
* [Wiggle Sort II (Medium)](https://leetcode.com/problems/wiggle-sort-ii/)


## Solution 1.

**Intuition**: If `a < b` and `a < c`, this sequence `b, a, c` must be valid. Similarly, if `a > b` and `a > c`, `b, a, c` is also valid.

**Algorithm**:

* Sort the array `A`.
* Fill the even positions with the small half numbers.
* Fill the odd positions with the great half numbers.

For example, `A = [1, 2, 3, 4, 5]`:
* Filling the even positions: `ans = [1, ?, 2, ?, 3]`
* Filling the odd positions: `ans = [1, 4, 2, 5, 3]`.

The space complexity is `O(N)` because if we can't alter the original array, we have to copy the original array, sort it, then copy values into the answer array.


```cpp
// OJ: https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& A) {
        sort(begin(A), end(A));
        int N = A.size(), i = 0;
        vector<int> ans(N);
        for (int j = 0; j < N; j += 2) ans[j] = A[i++];
        for (int j = 1; j < N; j += 2) ans[j] = A[i++];
        return ans;
    }
};
```

## Solution 2.

* Sort the array.
* Swap every two pairs of numbers.

Example: `A = [1,2,3,4,5]`. We swap `1, 2`, and `3, 4`. `A` becomes `[2,1,4,3,5]`.

The space complexity is `O(1)` because we can copy the original array into the answer array, sort the answer array, and swap values in place in the answer array. We don't count the size of the answer array into space complexity because they are needed anyway.

```cpp
// OJ: https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& A) {
        sort(begin(A), end(A));
        for (int i = 0; i + 1 < A.size(); i += 2) {
            swap(A[i], A[i + 1]);
        }
        return A;
    }
};
```

## NOTE

The key is to find ways to turn the input array into a wiggle array. That is, `A[0] < A[1] > A[2] < A[3] ...`.