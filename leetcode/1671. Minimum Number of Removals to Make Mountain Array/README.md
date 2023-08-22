# [1671. Minimum Number of Removals to Make Mountain Array (Hard)](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array)

<p>You may recall that an array <code>arr</code> is a <strong>mountain array</strong> if and only if:</p>
<ul>
	<li><code>arr.length &gt;= 3</code></li>
	<li>There exists some index <code>i</code> (<strong>0-indexed</strong>) with <code>0 &lt; i &lt; arr.length - 1</code> such that:
	<ul>
		<li><code>arr[0] &lt; arr[1] &lt; ... &lt; arr[i - 1] &lt; arr[i]</code></li>
		<li><code>arr[i] &gt; arr[i + 1] &gt; ... &gt; arr[arr.length - 1]</code></li>
	</ul>
	</li>
</ul>
<p>Given an integer array <code>nums</code>​​​, return <em>the <strong>minimum</strong> number of elements to remove to make </em><code>nums<em>​​​</em></code><em> </em><em>a <strong>mountain array</strong>.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,3,1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The array itself is a mountain array so we do not need to remove any elements.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [2,1,1,5,6,2,3,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>3 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li>It is guaranteed that you can make a mountain array out of <code>nums</code>.</li>
</ul>

**Companies**:
[Apple](https://leetcode.com/company/apple), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/longest-increasing-subsequence/)
* [Longest Mountain in Array (Medium)](https://leetcode.com/problems/longest-mountain-in-array/)
* [Peak Index in a Mountain Array (Medium)](https://leetcode.com/problems/peak-index-in-a-mountain-array/)
* [Valid Mountain Array (Easy)](https://leetcode.com/problems/valid-mountain-array/)
* [Find in Mountain Array (Hard)](https://leetcode.com/problems/find-in-mountain-array/)

## Solution 1. Three passes

### Intuition

Assume we pick `A[i]` as the peak of the mountain, then we are looking for the longest increasing subsequence to the left of `A[i]`, and the longest decreasing subsequence to the right of `A[i]`.

We can reuse the `O(NlogN)` time **binary search** solution to [300. Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/longest-increasing-subsequence/).

For the binary search solution to problem 300, please checkout [my explanation](../300.%20Longest%20Increasing%20Subsequence).

### Algorithm

Let `left[i]` be the length of the longest increasing subsequence in `A[0..(i-1)]` that can has `A[i]` appended to it, and `right[i]` be the length of the longest decreasing subsequence in `A[(i+1)..(N-1)]` that can has `A[i]` prepended to it.

We can scan from left to right to set the `left[i]` values, and scan from right to left to set the `right[i]` values.

For `1 <= i <= N - 2`, the longest mountain size is `left[i] + right[i] + 1`.

So the answer is the minimum `N - (left[i] + right[i] + 1)`.

Note that we need to skip cases where either `left[i]` or `right[i]` is zero because it's invalid.

Test cases that should be added:
* `[1,2,1,2,3,4]` and `[4,3,2,1,2,1]`. Correct answer is `3`.
* `[1,2,1,1,2,3,4,5]` and `[5,4,3,2,1,1,2,1]`. Correct answer is `5`.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int minimumMountainRemovals(vector<int>& A) {
        int N = A.size(), maxLen = 0;
        vector<int> left(N), right(N), tmp;
        for (int i = 0; i < N; ++i) {
            int j = lower_bound(begin(tmp), end(tmp), A[i]) - begin(tmp);
            if (j == tmp.size()) tmp.emplace_back();
            tmp[j] = A[i];
            left[i] = j;
        }
        tmp.clear();
        for (int i = N - 1; i >= 0; --i) {
            int j = lower_bound(begin(tmp), end(tmp), A[i]) - begin(tmp);
            if (j == tmp.size()) tmp.emplace_back();
            tmp[j] = A[i];
            right[i] = j;
        }
        for (int i = 1; i < N - 1; ++i) maxLen = max(maxLen, left[i] && right[i] ? left[i] + right[i] + 1 : 0);
        return N - maxLen;
    }
};
```

We don't have to store `right` array. Instead, we can update the answer when we compute the `right` values.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int minimumMountainRemovals(vector<int>& A) {
        int N = A.size(), ans = N;
        vector<int> left(N), tmp;
        for (int i = 0; i < N; ++i) {
            int j = lower_bound(begin(tmp), end(tmp), A[i]) - begin(tmp);
            if (j == tmp.size()) tmp.emplace_back();
            tmp[j] = A[i];
            left[i] = j;
        }
        tmp.clear();
        for (int i = N - 1; i >= 0; --i) {
            int j = lower_bound(begin(tmp), end(tmp), A[i]) - begin(tmp);
            if (j == tmp.size()) tmp.emplace_back();
            tmp[j] = A[i];
            if (left[i] && j) ans = min(ans, N - (left[i] + j + 1));
        }
        return ans;
    }
};
```