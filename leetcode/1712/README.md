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

## Solution 1. Binary Search

Turn array `A` into its prefix sum array. 

Let `i` be the last index of the `left` part. So `A[i]` is the sum of the `left` part.

For each `i`, we use binary search to find the range of the last index of the `mid` part.

For `mid >= left`, we have `left + mid >= 2 * left`, so we need to find the first prefix sum that is `>= 2 * left`.

For `mid <= right`, we have `mid <= total - left - mid`, so `mid <= (total - left) / 2`, so we need to find the last prefix sum that is `<= left + (total - left) / 2`.

Note that the valid range of the last index of the `mid` part is `[i + 1, N - 1)`, so we need to make sure our binary search is searching within this range.

```cpp
// OJ: https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1) if we are allowed to change the input array; otherwise O(N)
class Solution {
public:
    int waysToSplit(vector<int>& A) {
        long N = A.size(), mod = 1e9 + 7, ans = 0;
        partial_sum(begin(A), end(A), begin(A));
        for (int i = 0; i < N - 2; ++i) {
            int j = lower_bound(begin(A) + i + 1, end(A) - 1, A[i] * 2) - begin(A);
            int k = upper_bound(begin(A) + j, end(A) - 1, A[i] + (A.back() - A[i]) / 2) - begin(A);
            ans = (ans + k - j) % mod;
        }
        return ans;
    }
};
```
## Solution 2. Three Pointers

Turn array `A` into its prefix sum array. 

Let `i` be the last index of the `left` part. So `A[i]` is the sum of the `left` part.

Given `i`, the last index of the `mid` part is a range. Let it be `[j, k)`. 

**Key Point: When we increment `i`, `j` and `k` must increase monotonically.**

To find `j`, we can increment `j` from `i + 1` until `left <= mid` i.e. `A[j] - A[i] >= A[i]`.

To find `k`, we can keep incrementing `k` from `j` while it's valid -- i.e. `k <= N-2` and `mid <= right` (`A[k]-A[i] <= A[N-1]-A[k]`)

For each `i`, we add `k - j` to the answer.

Note that the valid range of the last index of `mid` is `[i + 1, N - 2]`.

```cpp
// OJ: https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) if we allow changing the input array; otherwise O(N)
class Solution {
public:
    int waysToSplit(vector<int>& A) {
        partial_sum(begin(A), end(A), begin(A));
        long mod = 1e9+7, ans = 0, N = A.size(), i = 0, j = 0, k = 0;
        for (; i < N; ++i) {
            j = max(i + 1, j); // `j` is at least one greater than `i`.
            while (j <= N - 2 && A[j] - A[i] < A[i]) ++j; // find the smallest `j <= N - 2` that satisfies `mid >= left`
            if (j > N - 2) break; // No room for the right part. Break
            k = max(k, j); // `k` is at least the same as `j`
            while (k <= N - 2 && A[k] - A[i] <= A.back() - A[k]) ++k; // keep incrementing `k` while it's valid -- `k <= N - 2` and `mid <= right`
            ans = (ans + k - j) % mod;
        }
        return ans;
    }
};
```

Or, we can calculate the sums on the fly without using prefix sums. In this way, we get real `O(1)` space.

```cpp
// OJ: https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int waysToSplit(vector<int>& A) {
        long N = A.size(), mod = 1e9 + 7, left = 0, total = accumulate(begin(A), end(A), 0L), mid1 = A[0], mid2 = A[0], ans = 0;
        for (int i = 0, j = 0, k = 0; i < N - 2; ++i) {
            left += A[i];
            mid1 -= A[i];
            mid2 -= A[i];
            while (j <= i) mid1 += A[++j];
            while (j <= N - 2 && mid1 < left) mid1 += A[++j];
            if (j > N - 2) break;
            while (k < j) mid2 += A[++k];
            while (k <= N - 2 && mid2 <= total - mid2 - left) mid2 += A[++k];
            ans = (ans + k - j) % mod;
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/discuss/999795/C%2B%2B-3-Pointers-O(N)-Time-O(1)-Space