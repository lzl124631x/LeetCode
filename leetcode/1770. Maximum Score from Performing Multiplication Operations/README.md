# [1770. Maximum Score from Performing Multiplication Operations (Medium)](https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/)

<p>You are given two integer arrays <code>nums</code> and <code>multipliers</code><strong> </strong>of size <code>n</code> and <code>m</code> respectively, where <code>n &gt;= m</code>. The arrays are <strong>1-indexed</strong>.</p>

<p>You begin with a score of <code>0</code>. You want to perform <strong>exactly</strong> <code>m</code> operations. On the <code>i<sup>th</sup></code> operation <strong>(1-indexed)</strong>, you will:</p>

<ul>
	<li>Choose one integer <code>x</code> from <strong>either the start or the end </strong>of the array <code>nums</code>.</li>
	<li>Add <code>multipliers[i] * x</code> to your score.</li>
	<li>Remove <code>x</code> from the array <code>nums</code>.</li>
</ul>

<p>Return <em>the <strong>maximum</strong> score after performing </em><code>m</code> <em>operations.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3], multipliers = [3,2,1]
<strong>Output:</strong> 14
<strong>Explanation:</strong>&nbsp;An optimal solution is as follows:
- Choose from the end, [1,2,<strong><u>3</u></strong>], adding 3 * 3 = 9 to the score.
- Choose from the end, [1,<strong><u>2</u></strong>], adding 2 * 2 = 4 to the score.
- Choose from the end, [<strong><u>1</u></strong>], adding 1 * 1 = 1 to the score.
The total score is 9 + 4 + 1 = 14.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
<strong>Output:</strong> 102
<strong>Explanation: </strong>An optimal solution is as follows:
- Choose from the start, [<u><strong>-5</strong></u>,-3,-3,-2,7,1], adding -5 * -10 = 50 to the score.
- Choose from the start, [<strong><u>-3</u></strong>,-3,-2,7,1], adding -3 * -5 = 15 to the score.
- Choose from the start, [<strong><u>-3</u></strong>,-2,7,1], adding -3 * 3 = -9 to the score.
- Choose from the end, [-2,7,<strong><u>1</u></strong>], adding 1 * 4 = 4 to the score.
- Choose from the end, [-2,<strong><u>7</u></strong>], adding 7 * 6 = 42 to the score. 
The total score is 50 + 15 - 9 + 4 + 42 = 102.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>m == multipliers.length</code></li>
	<li><code>1 &lt;= m &lt;= 10<sup>3</sup></code></li>
	<li><code>m &lt;= n &lt;= 10<sup>5</sup></code><code> </code></li>
	<li><code>-1000 &lt;= nums[i], multipliers[i] &lt;= 1000</code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Stone Game VII (Medium)](https://leetcode.com/problems/stone-game-vii/)

## Solution 1. DP

This is a search problem and there are overlapping subproblems, so we can use DP to solve it.

Let `dp[j][i]` be the maximum score we can get using `M[0..j]` and a subarray of `A` that starts at `i` and has `j` elements less than `A` (because they are already selected). For the previous `j` steps, we already selected `j` elements out of `A`, and since there are `i` selected elements in front of the subarray, there are `j - i` selected elements after the subarray. So the index of the last element of the subarray is `r = A.size() - j + i - 1`.

```
dp[j][i] = max(
                A[i] * M[j] + dp[i + 1][j + 1], // select A[i]
                A[r] * M[j] + dp[i][j + 1], // select A[r]
)
where r = A.size() - j + i - 1
```

Note:
1. The range of `i` is `[0, M.size() - 1]` so we just need `M` instead of `N` for the second dimension of `dp`.
1. that for simplicity, we used `0` as unvisited number here. But since `0` is a valid score, when the `memo[j][i]` is indeed `0`, we will recompute the value and thus waste time. We can initialize `memo[j][i]` to `INT_MIN` instead.

```cpp
// OJ: https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
// Author: github.com/lzl124631x
// Time: O(M^2)
// Space: O(M^2)
class Solution {
    int memo[1001][1001] = {};
    int dfs(vector<int> &A, vector<int> &M, int i, int j) {
        if (j == M.size()) return 0;
        if (memo[j][i]) return memo[j][i];
        return memo[j][i] = max(A[i] * M[j] + dfs(A, M, i + 1, j + 1), A[A.size() - j + i - 1] * M[j] + dfs(A, M, i, j + 1));
    }
public:
    int maximumScore(vector<int>& A, vector<int>& M) {
        return dfs(A, M, 0, 0);
    }
};
```