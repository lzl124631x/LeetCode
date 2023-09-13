# [1937. Maximum Number of Points with Cost (Medium)](https://leetcode.com/problems/maximum-number-of-points-with-cost/)

<p>You are given an <code>m x n</code> integer matrix <code>points</code> (<strong>0-indexed</strong>). Starting with <code>0</code> points, you want to <strong>maximize</strong> the number of points you can get from the matrix.</p>

<p>To gain points, you must pick one cell in <strong>each row</strong>. Picking the cell at coordinates <code>(r, c)</code> will <strong>add</strong> <code>points[r][c]</code> to your score.</p>

<p>However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows <code>r</code> and <code>r + 1</code> (where <code>0 &lt;= r &lt; m - 1</code>), picking cells at coordinates <code>(r, c<sub>1</sub>)</code> and <code>(r + 1, c<sub>2</sub>)</code> will <strong>subtract</strong> <code>abs(c<sub>1</sub> - c<sub>2</sub>)</code> from your score.</p>

<p>Return <em>the <strong>maximum</strong> number of points you can achieve</em>.</p>

<p><code>abs(x)</code> is defined as:</p>

<ul>
	<li><code>x</code> for <code>x &gt;= 0</code>.</li>
	<li><code>-x</code> for <code>x &lt; 0</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong><strong> </strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/12/screenshot-2021-07-12-at-13-40-26-diagram-drawio-diagrams-net.png" style="width: 300px; height: 300px;">
<pre><strong>Input:</strong> points = [[1,2,3],[1,5,1],[3,1,1]]
<strong>Output:</strong> 9
<strong>Explanation:</strong>
The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
You add 3 + 5 + 3 = 11 to your score.
However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
Your final score is 11 - 2 = 9.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/12/screenshot-2021-07-12-at-13-42-14-diagram-drawio-diagrams-net.png" style="width: 200px; height: 299px;">
<pre><strong>Input:</strong> points = [[1,5],[2,3],[4,2]]
<strong>Output:</strong> 11
<strong>Explanation:</strong>
The blue cells denote the optimal cells to pick, which have coordinates (0, 1), (1, 1), and (2, 0).
You add 5 + 3 + 4 = 12 to your score.
However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
Your final score is 12 - 1 = 11.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == points.length</code></li>
	<li><code>n == points[r].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= points[r][c] &lt;= 10<sup>5</sup></code></li>
</ul>


**Similar Questions**:
* [Minimum Path Sum (Medium)](https://leetcode.com/problems/minimum-path-sum/)

## Solution 1. DP

Let `dp[i+1][j]` be the maximum point we can get with first `i` rows if we selected `A[i+1][j]` in the `i`th row.

For the `0`th row:

```
dp[0][j] = A[0][j]
```

For the `i`th row (`i >= 1`):
```
dp[i+1][j] = max( dp[i][t] + A[i+1][j] - abs(t - j) | 0 <= t < N )
         = A[i+1][j] + max( dp[i][t] - abs(t - j) | 0 <= t < N )
         = max(
                A[i+1][j] + max( dp[i][t] - j + t | 0 <= t < j ),
                A[i+1][j] + max( dp[i][t] - t + j | j <= t < N )
              )
         = max(
                A[i+1][j] - j + max( dp[i][t] + t | 0 <= t < j ),
                A[i+1][j] + j + max( dp[i][t] - t | j <= t < N )
              )
```

This means that for a given `dp[i+1][j]`, we need to compute:

* `max( dp[i][t] + t | 0 <= t < j )`
* `max( dp[i][t] - t | j <= t < N )`

So we can do it in two pass:
1. First pass, from left to right. `dp[i+1][j] = A[i+1][j] - j + mx` where `mx = max( dp[i][t] + t | 0 <= t <= j )`
2. Second pass, from right to left. `dp[i+1][j] = max( dp[i+1][j], A[i+1][j] + j + mx)` where `mx = max( dp[i][t] - t | j <= t < N )`.

Since `dp[i+1][j]` is only dependent on the values in the previous row, we can reduce space of `dp` from `M * N` to `1 * N`.

The result is `max( dp[N - 1][j] | 0 <= j < N )`.

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-points-with-cost/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    long long maxPoints(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        vector<long long> dp(N);
        for (int i = 0; i < N; ++i) dp[i] = A[0][i];
        for (int i = 1; i < M; ++i) {
            vector<long long> next(N);
            long long mx = dp[0];
            for (int j = 0; j < N; ++j) {
                mx = max(mx, dp[j] + j);
                next[j] = A[i][j] - j + mx;
            }
            mx = dp[N - 1] - (N - 1);
            for (int j = N - 1; j >= 0; --j) {
                mx = max(mx, dp[j] - j);
                next[j] = max(next[j], A[i][j] + j + mx);
            }
            swap(next, dp);
        }
        return *max_element(begin(dp), end(dp));
    }
};
```