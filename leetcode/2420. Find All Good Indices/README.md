# [2420. Find All Good Indices (Medium)](https://leetcode.com/problems/find-all-good-indices)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> of size <code>n</code> and a positive integer <code>k</code>.</p>
<p>We call an index <code>i</code> in the range <code>k &lt;= i &lt; n - k</code> <strong>good</strong> if the following conditions are satisfied:</p>
<ul>
	<li>The <code>k</code> elements that are just <strong>before</strong> the index <code>i</code> are in <strong>non-increasing</strong> order.</li>
	<li>The <code>k</code> elements that are just <strong>after</strong> the index <code>i</code> are in <strong>non-decreasing</strong> order.</li>
</ul>
<p>Return <em>an array of all good indices sorted in <strong>increasing</strong> order</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [2,1,1,1,3,4,1], k = 2
<strong>Output:</strong> [2,3]
<strong>Explanation:</strong> There are two good indices in the array:
- Index 2. The subarray [2,1] is in non-increasing order, and the subarray [1,3] is in non-decreasing order.
- Index 3. The subarray [1,1] is in non-increasing order, and the subarray [3,4] is in non-decreasing order.
Note that the index 4 is not good because [4,1] is not non-decreasing.</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [2,1,1,2], k = 2
<strong>Output:</strong> []
<strong>Explanation:</strong> There are no good indices in this array.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>n == nums.length</code></li>
	<li><code>3 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= n / 2</code></li>
</ul>

**Companies**:
[Goldman Sachs](https://leetcode.com/company/goldman-sachs)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Find Good Days to Rob the Bank (Medium)](https://leetcode.com/problems/find-good-days-to-rob-the-bank/)
* [Abbreviating the Product of a Range (Hard)](https://leetcode.com/problems/abbreviating-the-product-of-a-range/)
* [Count the Number of K-Big Indices (Hard)](https://leetcode.com/problems/count-the-number-of-k-big-indices/)

## Solution 1. Fixed-length Sliding Window

```cpp
// OJ: https://leetcode.com/problems/find-all-good-indices
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(K)
class Solution {
public:
    vector<int> goodIndices(vector<int>& A, int k) {
        vector<int> ans;
        deque<int> left, right;
        for (int i = 0, N = A.size(); i < N; ++i) {
            if (i - k - 1 >= 0) {
                while (left.size() && A[left.back()] < A[i - k - 1]) left.pop_back();
                left.push_back(i - k - 1);
            }
            if (left.size() && left.front() < i - 2 * k) left.pop_front();
            while (right.size() && A[right.back()] > A[i]) right.pop_back();
            right.push_back(i);
            if (right.front() == i - k) right.pop_front();
            if (left.size() == k && right.size() == k) ans.push_back(i - k);
        }
        return ans;
    }
};
```

## Solution 2. DP

```cpp
// OJ: https://leetcode.com/problems/find-all-good-indices
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> goodIndices(vector<int>& A, int k) {
        int N = A.size();
        vector<int> ans, left(N, 1), right(N, 1);
        for (int i = 1; i < N; ++i) {
            if (A[i] <= A[i - 1]) left[i] = left[i - 1] + 1;
        }
        for (int i = N - 2; i >= 0; --i) {
            if (A[i] <= A[i + 1]) right[i] = right[i + 1] + 1;
        }
        for (int i = k; i < N - k; ++i) {
            if (left[i - 1] >= k && right[i + 1] >= k) ans.push_back(i);
        }
        return ans;
    }
};
```