# [2547. Minimum Cost to Split an Array (Hard)](https://leetcode.com/problems/minimum-cost-to-split-an-array)

<p>You are given an integer array <code>nums</code> and an integer <code>k</code>.</p>

<p>Split the array into some number of non-empty subarrays. The <strong>cost</strong> of a split is the sum of the <strong>importance value</strong> of each subarray in the split.</p>

<p>Let <code>trimmed(subarray)</code> be the version of the subarray where all numbers which appear only once are removed.</p>

<ul>
	<li>For example, <code>trimmed([3,1,2,4,3,4]) = [3,4,3,4].</code></li>
</ul>

<p>The <strong>importance value</strong> of a subarray is <code>k + trimmed(subarray).length</code>.</p>

<ul>
	<li>For example, if a subarray is <code>[1,2,3,3,3,4,4]</code>, then <font face="monospace">trimmed(</font><code>[1,2,3,3,3,4,4]) = [3,3,3,4,4].</code>The importance value of this subarray will be <code>k + 5</code>.</li>
</ul>

<p>Return <em>the minimum possible cost of a split of </em><code>nums</code>.</p>

<p>A <strong>subarray</strong> is a contiguous <strong>non-empty</strong> sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,1,2,1,3,3], k = 2
<strong>Output:</strong> 8
<strong>Explanation:</strong> We split nums to have two subarrays: [1,2], [1,2,1,3,3].
The importance value of [1,2] is 2 + (0) = 2.
The importance value of [1,2,1,3,3] is 2 + (2 + 2) = 6.
The cost of the split is 2 + 6 = 8. It can be shown that this is the minimum possible cost among all the possible splits.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,1,2,1], k = 2
<strong>Output:</strong> 6
<strong>Explanation:</strong> We split nums to have two subarrays: [1,2], [1,2,1].
The importance value of [1,2] is 2 + (0) = 2.
The importance value of [1,2,1] is 2 + (2) = 4.
The cost of the split is 2 + 4 = 6. It can be shown that this is the minimum possible cost among all the possible splits.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,1,2,1], k = 5
<strong>Output:</strong> 10
<strong>Explanation:</strong> We split nums to have one subarray: [1,2,1,2,1].
The importance value of [1,2,1,2,1] is 5 + (3 + 2) = 10.
The cost of the split is 10. It can be shown that this is the minimum possible cost among all the possible splits.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt; nums.length</code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>
<style type="text/css">.spoilerbutton {display:block; border:dashed; padding: 0px 0px; margin:10px 0px; font-size:150%; font-weight: bold; color:#000000; background-color:cyan; outline:0; 
}
.spoiler {overflow:hidden;}
.spoiler > div {-webkit-transition: all 0s ease;-moz-transition: margin 0s ease;-o-transition: all 0s ease;transition: margin 0s ease;}
.spoilerbutton[value="Show Message"] + .spoiler > div {margin-top:-500%;}
.spoilerbutton[value="Hide Message"] + .spoiler {padding:5px;}
</style>


**Companies**:
[Indeed](https://leetcode.com/company/indeed)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Hash Table](https://leetcode.com/tag/hash-table), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming), [Counting](https://leetcode.com/tag/counting)

**Similar Questions**:
* [Coin Change (Medium)](https://leetcode.com/problems/coin-change)
* [Split Array Largest Sum (Hard)](https://leetcode.com/problems/split-array-largest-sum)

**Hints**:
* Let's denote dp[r] = minimum cost to partition the first r elements of nums. What would be the transitions of such dynamic programming?
* dp[r] = min(dp[l] + importance(nums[l..r])) over all 0 <= l < r. This already gives us an O(n^3) approach, as importance can be calculated in linear time, and there are a total of O(n^2) transitions.
* Can you think of a way to compute multiple importance values of related subarrays faster?
* importance(nums[l-1..r]) is either importance(nums[l..r]) if a new unique element is added, importance(nums[l..r]) + 1 if an old element that appeared at least twice is added, or importance(nums[l..r]) + 2, if a previously unique element is duplicated. This allows us to compute importance(nums[l..r]) for all 0 <= l < r in O(n) by keeping a frequency table and decreasing l from r-1 down to 0.

## Solution 1. DP

Let `dp[i+1]` be the min cost of splitting `A[0..i]`. The answer is `dp[N]`.

```
dp[0] = 0
// for 0 <= i < N
dp[i+1] = min(dp[j] + importance[j][i] | 0 <= j <= i )

importance[j][i] = k + (i - j + 1) - uniqueCnt[j][i]
```

```cpp
// OJ: https://leetcode.com/problems/minimum-cost-to-split-an-array
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int minCost(vector<int>& A, int k) {
        int N = A.size(), importance[1000][1000] = {}, dp[1002] = {[0 ... 1001] = INT_MAX};
        for (int i = 0; i < N; ++i) {
            bool seen[1001] = {};
            unordered_set<int> s;
            for (int j = i; j < N; ++j) {
                if (seen[A[j]]) s.erase(A[j]);
                else {
                    seen[A[j]] = true;
                    s.insert(A[j]);
                }
                importance[i][j] = k + j - i + 1 - s.size();
            }
        }
        dp[0] = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= i; ++j) {
                dp[i + 1] = min(dp[i + 1], dp[j] + importance[j][i]);
            }
        }
        return dp[N];
    }
};
```