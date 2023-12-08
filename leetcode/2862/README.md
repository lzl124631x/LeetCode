# [2862. Maximum Element-Sum of a Complete Subset of Indices (Hard)](https://leetcode.com/problems/maximum-element-sum-of-a-complete-subset-of-indices)

<p>You are given a <strong>1</strong><strong>-indexed</strong> array <code>nums</code> of <code>n</code> integers.</p>

<p>A set of numbers is <strong>complete</strong> if the product of every pair of its elements is a perfect square.</p>

<p>For a subset of the indices set <code>{1, 2, ..., n}</code> represented as <code>{i<sub>1</sub>, i<sub>2</sub>, ..., i<sub>k</sub>}</code>, we define its <strong>element-sum</strong> as: <code>nums[i<sub>1</sub>] + nums[i<sub>2</sub>] + ... + nums[i<sub>k</sub>]</code>.</p>

<p>Return <em>the <strong>maximum element-sum</strong> of a <strong>complete</strong> subset of the indices set</em> <code>{1, 2, ..., n}</code>.</p>

<p>A perfect square is a number that can be expressed as the product of an integer by itself.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [8,7,3,5,7,2,4,9]
<strong>Output:</strong> 16
<strong>Explanation:</strong> Apart from the subsets consisting of a single index, there are two other complete subsets of indices: {1,4} and {2,8}.
The sum of the elements corresponding to indices 1 and 4 is equal to nums[1] + nums[4] = 8 + 5 = 13.
The sum of the elements corresponding to indices 2 and 8 is equal to nums[2] + nums[8] = 7 + 9 = 16.
Hence, the maximum element-sum of a complete subset of indices is 16.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [5,10,3,10,1,13,7,9,4]
<strong>Output:</strong> 19
<strong>Explanation:</strong> Apart from the subsets consisting of a single index, there are four other complete subsets of indices: {1,4}, {1,9}, {2,8}, {4,9}, and {1,4,9}.
The sum of the elements corresponding to indices 1 and 4 is equal to nums[1] + nums[4] = 5 + 10 = 15.
The sum of the elements corresponding to indices 1 and 9 is equal to nums[1] + nums[9] = 5 + 4 = 9.
The sum of the elements corresponding to indices 2 and 8 is equal to nums[2] + nums[8] = 10 + 9 = 19.
The sum of the elements corresponding to indices 4 and 9 is equal to nums[4] + nums[9] = 10 + 4 = 14.
The sum of the elements corresponding to indices 1, 4, and 9 is equal to nums[1] + nums[4] + nums[9] = 5 + 10 + 4 = 19.
Hence, the maximum element-sum of a complete subset of indices is 19.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:
[purplle](https://leetcode.com/company/purplle)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Math](https://leetcode.com/tag/math), [Number Theory](https://leetcode.com/tag/number-theory)

**Similar Questions**:
* [Constrained Subsequence Sum (Hard)](https://leetcode.com/problems/constrained-subsequence-sum)
* [Maximum Alternating Subsequence Sum (Medium)](https://leetcode.com/problems/maximum-alternating-subsequence-sum)

**Hints**:
* Let <code>P(x)</code> be the product of all prime numbers <code>p</code> such that <code>p</code> divides <code>x</code>, and there exists an <strong>odd</strong> <code>k</code> such that <code>p^k</code> divides <code>x</code> but <code>p^(k+1)</code> does not.
* If <code>P(nums[i]) = P(nums[j])</code>, <code>nums[i]</code> and <code>nums[j]</code> can be grouped together.
* Pick the group with the largest sum.

## Solution 1.

Assume the index is in range `[1, 9]`, we have the following complete subsets.

```
1 elements -> {1} {4} {9} 
2 elements -> {1,4}, {1,9}
              {2,8},
              {4,9}
3 elements -> {1,4,9}
```

The 3 elements one is special because it contains all the sqaure values in the index set. Also, it covers all other subsets except `{2,8}`.

This `{2,8}` can be regarded as `{1*2,4*2}`, that is, `{1,4}` multiplied by `2` to each of its elements.

So the algorithm can be as follows:

1. Collect all the square indices as the initial `idx` subset, and calculate its element-sum, taking `O(sqrt(N))` time and `O(sqrt(N))` space.
2. Multiply the `idx` subset with `i=2,3,4,...`, remove out-of-bound indices, and calculate its element-sum. Repeat this step until the subset is empty. The multiplier `i` is at most `N` -- the corresponding subset is `{1*N}`, so the outer loop runs `O(N)` times. The inner loop runs `O(sqrt(N))` times. So it takes `O(N * sqrt(N))` time in total.

```cpp
// OJ: https://leetcode.com/problems/maximum-element-sum-of-a-complete-subset-of-indices
// Author: github.com/lzl124631x
// Time: O(N * sqrt(N))
// Space: O(sqrt(N))
class Solution {
public:
    long long maximumSum(vector<int>& A) {
        int N = A.size();
        long long ans = 0;
        vector<int> idx;
        for (int i = 1; i * i <= N; ++i) {
            idx.push_back(i * i);
            ans += A[i * i - 1];
        }
        for (int i = 2, j = idx.size() - 1; i <= N; ++i) {
            while (j >= 0 && idx[j] * i > N) --j;
            long long sum = 0;
            for (int k = 0; k <= j; ++k) sum += A[idx[k] * i - 1];
            ans = max(sum, ans);
        }
        return ans;
    }
};
```