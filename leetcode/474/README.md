# [474. Ones and Zeroes (Medium)](https://leetcode.com/problems/ones-and-zeroes)

<p>You are given an array of binary strings <code>strs</code> and two integers <code>m</code> and <code>n</code>.</p>

<p>Return <em>the size of the largest subset of <code>strs</code> such that there are <strong>at most</strong> </em><code>m</code><em> </em><code>0</code><em>&#39;s and </em><code>n</code><em> </em><code>1</code><em>&#39;s in the subset</em>.</p>

<p>A set <code>x</code> is a <strong>subset</strong> of a set <code>y</code> if all elements of <code>x</code> are also elements of <code>y</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> strs = [&quot;10&quot;,&quot;0001&quot;,&quot;111001&quot;,&quot;1&quot;,&quot;0&quot;], m = 5, n = 3
<strong>Output:</strong> 4
<strong>Explanation:</strong> The largest subset with at most 5 0&#39;s and 3 1&#39;s is {&quot;10&quot;, &quot;0001&quot;, &quot;1&quot;, &quot;0&quot;}, so the answer is 4.
Other valid but smaller subsets include {&quot;0001&quot;, &quot;1&quot;} and {&quot;10&quot;, &quot;1&quot;, &quot;0&quot;}.
{&quot;111001&quot;} is an invalid subset because it contains 4 1&#39;s, greater than the maximum of 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> strs = [&quot;10&quot;,&quot;0&quot;,&quot;1&quot;], m = 1, n = 1
<strong>Output:</strong> 2
<b>Explanation:</b> The largest subset is {&quot;0&quot;, &quot;1&quot;}, so the answer is 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= strs.length &lt;= 600</code></li>
	<li><code>1 &lt;= strs[i].length &lt;= 100</code></li>
	<li><code>strs[i]</code> consists only of digits <code>&#39;0&#39;</code> and <code>&#39;1&#39;</code>.</li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
</ul>


**Companies**:
[Uber](https://leetcode.com/company/uber), [Google](https://leetcode.com/company/google), [Adobe](https://leetcode.com/company/adobe), [Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [String](https://leetcode.com/tag/string), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming)

**Similar Questions**:
* [Count Subarrays With More Ones Than Zeros (Medium)](https://leetcode.com/problems/count-subarrays-with-more-ones-than-zeros)
* [Non-negative Integers without Consecutive Ones (Hard)](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones)
* [All Divisions With the Highest Score of a Binary Array (Medium)](https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array)

## Solution 1. DP

Note: this is a 0-1 Knapsack problem.

Let `dp[i + 1][j][k]` be the answer of subproblem if we only use the first `i + 1` strings (`strs[0]` to `strs[i]`) given `m = j`, `n = k`.

```
dp[i + 1][j][k] = max(
                        dp[i][j][k],                          // If we don't use strs[i]
                        1 + dp[i][j - zero[i]][k - one[i]]    // If we use strs[i] 
                     )
```
where `zero[i]` and `one[i]` are the counts of zeros and ones in `strs[i]` respectively.

```cpp
// OJ: https://leetcode.com/problems/ones-and-zeroes/
// Author: github.com/lzl124631x
// Time: O(MNS)
// Space: O(MNS)
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int S = strs.size();
        vector<vector<vector<int>>> dp(S + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for (int i = 0; i < S; ++i) {
            int zero = count(strs[i].begin(), strs[i].end(), '0'), one = strs[i].size() - zero;
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    dp[i + 1][j][k] = max(dp[i][j][k], j >= zero && k >= one ? 1 + dp[i][j - zero][k - one] : 0);
                }
            }
        }
        return dp[S][m][n];
    }
};
```

## Solution 2. DP with Space Optimization

```cpp
// OJ: https://leetcode.com/problems/ones-and-zeroes/
// Author: github.com/lzl124631x
// Time: O(MNS)
// Space: O(MN)
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int S = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i < S; ++i) {
            int zero = count(strs[i].begin(), strs[i].end(), '0'), one = strs[i].size() - zero;
            for (int j = m; j >= zero; --j) {
                for (int k = n; k >= one; --k) {
                    dp[j][k] = max(dp[j][k], 1 + dp[j - zero][k - one]);
                }
            }
        }
        return dp[m][n];
    }
};
```