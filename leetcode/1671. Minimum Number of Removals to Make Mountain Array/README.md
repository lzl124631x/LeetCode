# [1671. Minimum Number of Removals to Make Mountain Array (Hard)](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/)

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
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,3,1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The array itself is a mountain array so we do not need to remove any elements.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,1,1,5,6,2,3,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [4,3,2,1,1,2,3,1]
<strong>Output:</strong> 4
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4,4,3,2,1]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li>It is guaranteed that you can make a mountain array out of <code>nums</code>.</li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/longest-increasing-subsequence/)
* [Longest Mountain in Array (Medium)](https://leetcode.com/problems/longest-mountain-in-array/)
* [Peak Index in a Mountain Array (Easy)](https://leetcode.com/problems/peak-index-in-a-mountain-array/)
* [Valid Mountain Array (Easy)](https://leetcode.com/problems/valid-mountain-array/)
* [Find in Mountain Array (Hard)](https://leetcode.com/problems/find-in-mountain-array/)

## Solution 1. Three passes O(NlogN)

### Intuition

Assume we pick `A[i]` as the peak of the mountain, then we are looking for the longest increasing subsequence to the left of `A[i]`, and the longest decreasing subsequence to the right of `A[i]`.

We can reuse the `O(NlogN)` time **binary search** solution to [300. Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/longest-increasing-subsequence/).

### Algorithm

Let `a[i]` be the length of the longest increasing subsequence in `A[0..(i-1)]`, and `b[i]` be the length of the longest decreasing subsequence in `A[(i+1)..(N-1)]`.

We can scan from left to right to set the `a[i]` values, and scan from right to left to set the `b[i]` values.

For `1 <= i <= N - 2`, the longest mountain size is `a[i] + b[i] + 1`.

So the answer is the minimum `N - (a[i] + b[i] + 1)`.

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int minimumMountainRemovals(vector<int>& A) {
        int N = A.size(), ans = N;
        vector<int> a(N), b(N), v;
        for (int i = 0 ; i < N; ++i) {
            int x = A[i];
            a[i] = lower_bound(begin(v), end(v), x) - begin(v);
            auto it = lower_bound(begin(v), end(v), x);
            if (it != end(v)) *it = x;
            else v.push_back(x);
        }
        v.clear();
        for (int i = N - 1; i >= 0; --i) {
            int x = A[i];
            b[i] = lower_bound(begin(v), end(v), x) - begin(v); 
            auto it = lower_bound(begin(v), end(v), x) ;
            if (it != end(v)) *it = x;
            else v.push_back(x);
        }
        for (int i = 1; i < N; ++i) ans = min(ans, N - (a[i] + b[i] + 1));
        return ans;
    }
};
```