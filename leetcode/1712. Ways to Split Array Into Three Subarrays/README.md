# [1712. Ways to Split Array Into Three Subarrays (Medium)](https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/)

<p>A split of an integer array is <strong>good</strong> if:</p>

<ul>
	<li>The array is split into three <strong>non-empty</strong> contiguous subarrays - named <code>left</code>, <code>mid</code>, <code>right</code> respectively from left to right.</li>
	<li>The sum of the elements in <code>left</code> is less than or equal to the sum of the elements in <code>mid</code>, and the sum of the elements in <code>mid</code> is less than or equal to the sum of the elements in <code>right</code>.</li>
</ul>

<p>Given <code>nums</code>, an array of <strong>non-negative</strong> integers, return <em>the number of <strong>good</strong> ways to split</em> <code>nums</code>. As the number may be too large, return it <strong>modulo</strong> <code>10<sup>9 </sup>+ 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The only good way to split nums is [1] [1] [1].</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,2,2,5,0]
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are three good ways of splitting nums:
[1] [2] [2,2,5,0]
[1] [2,2] [2,5,0]
[1,2] [2,2] [5,0]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [3,2,1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no good way to split nums.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1. Three Pointers

Turn array `A` into its prefix sum array. 

Let `i` be the last index of the `left` part. So `A[i]` is the sum of the `left` part.

Given `i`, the last index of the `mid` part is a range. Let it be `[j, k)`.

When we increment `i`, `j` and `k` must be monotonically increasing.

To find `j`, we can increment `j` from `i + 1` until `mid >= left` i.e. `A[j] - A[i] >= A[i]`.

To find `k`, we can increment `k` from `j` until `mid < right`, i.e. `A[N - 1] - A[k] < A[k] - A[i]`.

```cpp
// OJ: https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int waysToSplit(vector<int>& A) {
        long mod = 1e9+7, ans = 0;
        for (int i = 1; i < A.size(); ++i) A[i] += A[i - 1];
        long N = A.size(), i = 0, j = 0, k = 0;
        for (; i < N; ++i) {
            long left = A[i];
            j = max(i + 1, j); // `j` is at least one greater than `i`.
            while (j < N && A[j] - left < left) ++j; // find the smallest `j` that satisfies `mid >= left`
            if (j >= N) break; // No room for `k`. Break
            k = max(k, j);
            while (k < N - 1 && A.back() - A[k] >= A[k] - A[i]) ++k;
            ans = (ans + k - j) % mod;
        }
        return ans;
    }
};
```

## Solution 2. Binary Search

```cpp
// OJ: https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int waysToSplit(vector<int>& A) {
        long mod = 1e9 + 7, ans = 0, N = A.size();
        for (int i = 1; i < N; ++i) A[i] += A[i - 1];
        for (int i = 0; i < N; ++i) {
            long left = A[i], other = A.back() - left;
            int j = lower_bound(begin(A) + i + 1, end(A), 2 * left) - begin(A);
            int k = upper_bound(begin(A) + i + 1, end(A) - 1, left + other / 2) - begin(A);
            if (k > j) ans = (ans + k - j) % mod;
        }
        return ans;
    }
};
```