# [2312. Selling Pieces of Wood (Hard)](https://leetcode.com/problems/selling-pieces-of-wood)

<p>You are given two integers <code>m</code> and <code>n</code> that represent the height and width of a rectangular piece of wood. You are also given a 2D integer array <code>prices</code>, where <code>prices[i] = [h<sub>i</sub>, w<sub>i</sub>, price<sub>i</sub>]</code> indicates you can sell a rectangular piece of wood of height <code>h<sub>i</sub></code> and width <code>w<sub>i</sub></code> for <code>price<sub>i</sub></code> dollars.</p>
<p>To cut a piece of wood, you must make a vertical or horizontal cut across the <strong>entire</strong> height or width of the piece to split it into two smaller pieces. After cutting a piece of wood into some number of smaller pieces, you can sell pieces according to <code>prices</code>. You may sell multiple pieces of the same shape, and you do not have to sell all the shapes. The grain of the wood makes a difference, so you <strong>cannot</strong> rotate a piece to swap its height and width.</p>
<p>Return <em>the <strong>maximum</strong> money you can earn after cutting an </em><code>m x n</code><em> piece of wood</em>.</p>
<p>Note that you can cut the piece of wood as many times as you want.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/04/27/ex1.png" style="width: 239px; height: 150px;">
<pre><strong>Input:</strong> m = 3, n = 5, prices = [[1,4,2],[2,2,7],[2,1,3]]
<strong>Output:</strong> 19
<strong>Explanation:</strong> The diagram above shows a possible scenario. It consists of:
- 2 pieces of wood shaped 2 x 2, selling for a price of 2 * 7 = 14.
- 1 piece of wood shaped 2 x 1, selling for a price of 1 * 3 = 3.
- 1 piece of wood shaped 1 x 4, selling for a price of 1 * 2 = 2.
This obtains a total of 14 + 3 + 2 = 19 money earned.
It can be shown that 19 is the maximum amount of money that can be earned.
</pre>
<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/04/27/ex2new.png" style="width: 250px; height: 175px;">
<pre><strong>Input:</strong> m = 4, n = 6, prices = [[3,2,10],[1,4,2],[4,1,3]]
<strong>Output:</strong> 32
<strong>Explanation:</strong> The diagram above shows a possible scenario. It consists of:
- 3 pieces of wood shaped 3 x 2, selling for a price of 3 * 10 = 30.
- 1 piece of wood shaped 1 x 4, selling for a price of 1 * 2 = 2.
This obtains a total of 30 + 2 = 32 money earned.
It can be shown that 32 is the maximum amount of money that can be earned.
Notice that we cannot rotate the 1 x 4 piece of wood to obtain a 4 x 1 piece of wood.</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>1 &lt;= prices.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>prices[i].length == 3</code></li>
	<li><code>1 &lt;= h<sub>i</sub> &lt;= m</code></li>
	<li><code>1 &lt;= w<sub>i</sub> &lt;= n</code></li>
	<li><code>1 &lt;= price<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
	<li>All the shapes of wood <code>(h<sub>i</sub>, w<sub>i</sub>)</code> are pairwise <strong>distinct</strong>.</li>
</ul>

**Companies**:
[Palantir Technologies](https://leetcode.com/company/palantir-technologies)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Memoization](https://leetcode.com/tag/memoization/)

**Similar Questions**:
* [Tiling a Rectangle with the Fewest Squares (Hard)](https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/)
* [Number of Ways of Cutting a Pizza (Hard)](https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/)

## Solution 1. Top-down DP

```cpp
// OJ: https://leetcode.com/problems/selling-pieces-of-wood
// Author: github.com/lzl124631x
// Time: O(MN * (M + N))
// Space: O(MN)
class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& P) {
        long long memo[201][201] = {}, p[201][201] = {};
        memset(memo, -1, sizeof(memo));
        for (auto &v : P) p[v[0]][v[1]] = v[2];
        function<long long(int, int)> dp = [&](int h, int w) -> long long {
            if (memo[h][w] != -1) return memo[h][w];
            memo[h][w] = p[h][w];
            for (int i = 1; i <= h / 2; ++i) {
                memo[h][w] = max(memo[h][w], dp(i, w) + dp(h - i, w));
            }
            for (int j = 1; j <= w / 2; ++j) {
                memo[h][w] = max(memo[h][w], dp(h, j) + dp(h, w - j));
            }
            return memo[h][w];
        };
        return dp(m, n);
    }
};
```

## Solution 2. Bottom-up DP

```cpp
// OJ: https://leetcode.com/problems/selling-pieces-of-wood
// Author: github.com/lzl124631x
// Time: O(MN * (M + N))
// Space: O(MN)
class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& P) {
        long long dp[201][201] = {};
        for (auto &p : P) dp[p[0]][p[1]] = p[2];
        for (int h = 1; h <= m; ++h) {
            for (int w = 1; w <= n; ++w) {
                for (int x = 1; x <= h / 2; ++x) dp[h][w] = max(dp[h][w], dp[x][w] + dp[h - x][w]);
                for (int x = 1; x <= w / 2; ++x) dp[h][w] = max(dp[h][w], dp[h][x] + dp[h][w - x]);
            }
        }
        return dp[m][n];
    }
};
```