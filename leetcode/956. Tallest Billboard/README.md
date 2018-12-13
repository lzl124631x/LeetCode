# [956. Tallest Billboard (Hard)](https://leetcode.com/problems/tallest-billboard/)

<p>You are installing a billboard and want it to have the largest height.&nbsp; The billboard will have two steel supports, one on each side.&nbsp; Each steel support must be an equal height.</p>

<p>You have a collection of <code>rods</code> which can be welded together.&nbsp; For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.</p>

<p>Return the largest possible height of your billboard installation.&nbsp; If you cannot support the billboard, return 0.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[1,2,3,6]</span>
<strong>Output: </strong><span id="example-output-1">6</span>
<strong>Explanation:</strong> We have two disjoint subsets {1,2,3} and {6}, which have the same sum = 6.
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[1,2,3,4,5,6]</span>
<strong>Output: </strong><span id="example-output-2">10</span>
<strong>Explanation:</strong> We have two disjoint subsets {2,3,5} and {4,6}, which have the same sum = 10.
</pre>
</div>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">[1,2]</span>
<strong>Output: </strong><span id="example-output-3">0</span>
<strong>Explanation: </strong>The billboard cannot be supported, so we return 0.
</pre>
</div>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>0 &lt;= rods.length &lt;= 20</code></li>
	<li><code>1 &lt;= rods[i] &lt;= 1000</code></li>
	<li><code>The sum of rods is at most 5000.</code></li>
</ol>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

### Thought
For each rod `x`, we have 3 options:
1. use it in one post
1. use it in another post
1. don't use it.

If we turn all the numbers used in the first post to negative (turn `x` to `-x`), leave the numbers used in the second post as-is (`x` to `+x`), and turn all the numbers that are not used to `0`, this question turns into: 

Find the max score we can get after doing the above operations. The "score" is the sum of all the positive numbers. For example, `+1 +2 +3 -6` has a score of `6`.

Since `sum(rods)` is bounded, it suggests us to use this fact in some way.

A fact we should consider is that for a given `sum`, it doesn't matter how we get the `sum`.

For example, with `rods = [1,2,2,3]`, we could get sum `3` in 3 different ways. If we just consider `sum = 3`, we actually covered all those three cases.

Since `sum` is in range `[-5000, 5000]`, we just have `10001` numbers to consider.

### Algorithm

Let `dp[i][s]` be the largest score we can get using `rods[(i+1)..(N-1)]` to get sum `s`.

For example, for `rods = [1,2,3,6]`, we have `dp[1][1] = 5`, because after writing `1`, we could write `+2 +3 -6` to get sum `1`, and the corresponding score is `5`.

For the base case, `dp[rods.length][s]` is `0` when `s == 0`, and `-infinity` everywhere else.

The recursion is `dp[i][s] = max(dp[i+1][s], dp[i+1][s-rods[i]], rods[i] + dp[i+1][s+rods[i]])`.

NOTE: in the following implementation we use `sum = 5000` as `sum = 0` to simply code.

```cpp
// OJ: https://leetcode.com/problems/tallest-billboard
// Author: github.com/lzl124631x
// Time: O(NS) where N is the length of `rods`,
//             and S is the maximum of `sum(rods[i..j])`
// Space: O(NS)
// Ref: https://leetcode.com/articles/tallest-billboard/
class Solution {
private:
    vector<vector<int>> dp;
    int dfs(vector<int>& rods, int i, int s) {
        if (i == rods.size()) return s == 5000 ? 0 : INT_MIN;
        if (dp[i][s] != INT_MIN) return dp[i][s];
        int ans = dfs(rods, i + 1, s);
        ans = max(ans, dfs(rods, i + 1, s - rods[i]));
        ans = max(ans, rods[i] + dfs(rods, i + 1, s + rods[i]));
        return dp[i][s] = ans;
    }
public:
    int tallestBillboard(vector<int>& rods) {
        int N = rods.size();
        dp = vector<vector<int>>(N, vector<int>(10001, INT_MIN));
        return dfs(rods, 0, 5000);
    }
};
```