# [1473. Paint House III (Hard)](https://leetcode.com/problems/paint-house-iii/)

<p>There is&nbsp;a row of&nbsp;<code>m</code>&nbsp;houses in a small city, each house must be painted with one of the&nbsp;<code>n</code>&nbsp;colors (labeled from 1 to <code>n</code>), some houses that has been painted last summer should not be painted again.</p>

<p>A neighborhood is a maximal group of continuous houses that are painted with the same color. (For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods&nbsp; [{1}, {2,2}, {3,3}, {2}, {1,1}]).</p>

<p>Given an array <code>houses</code>, an&nbsp;<code>m * n</code>&nbsp;matrix <code>cost</code> and&nbsp;an integer <code><font face="monospace">target</font></code>&nbsp;where:</p>

<ul>
	<li><code>houses[i]</code>:&nbsp;is the color of the house <code>i</code>, <strong>0</strong> if the house is not painted yet.</li>
	<li><code>cost[i][j]</code>: is the cost of paint the house <code>i</code> with the color <code>j+1</code>.</li>
</ul>

<p>Return the minimum cost of painting all the&nbsp;remaining houses in such a way that there are exactly <code>target</code> neighborhoods, if&nbsp;not possible return <strong>-1</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> houses = [0,0,0,0,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
<strong>Output:</strong> 9
<strong>Explanation:</strong> Paint houses of this way [1,2,2,1,1]
This array contains target = 3 neighborhoods, [{1}, {2,2}, {1,1}].
Cost of paint all houses (1 + 1 + 1 + 1 + 5) = 9.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> houses = [0,2,1,2,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
<strong>Output:</strong> 11
<strong>Explanation:</strong> Some houses are already painted, Paint the houses of this way [2,2,1,2,2]
This array contains target = 3 neighborhoods, [{2,2}, {1}, {2,2}]. 
Cost of paint the first and last house (10 + 1) = 11.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> houses = [0,0,0,0,0], cost = [[1,10],[10,1],[1,10],[10,1],[1,10]], m = 5, n = 2, target = 5
<strong>Output:</strong> 5
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> houses = [3,1,2,3], cost = [[1,1,1],[1,1,1],[1,1,1],[1,1,1]], m = 4, n = 3, target = 3
<strong>Output:</strong> -1
<strong>Explanation:</strong> Houses are already painted with a total of 4 neighborhoods [{3},{1},{2},{3}] different of target = 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == houses.length == cost.length</code></li>
	<li><code>n == cost[i].length</code></li>
	<li><code>1 &lt;= m &lt;= 100</code></li>
	<li><code>1 &lt;= n &lt;= 20</code></li>
	<li><code>1 &lt;= target&nbsp;&lt;= m</code></li>
	<li><code>0 &lt;= houses[i]&nbsp;&lt;= n</code></li>
	<li><code>1 &lt;= cost[i][j] &lt;= 10^4</code></li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP Top-down

This looks like a DP problem because:
1. it involves searching
2. it only cares about the optimal solution -- Optimal substructure
3. During searching, we might go into the same state from different paths -- Overlapping sub-problems.

The first task we need to do is to design the state of the sub-problem. I identified three:

* the index of the current house (we scan them one by one from left to right). Denote it as `i`, `0 <= i < M`.
* The color of the previous house. Denote it as `last`, `0 <= last <= N`.
* Lastly, the count of the neighbors. Denote it as `cnt`, `0 <= cnt <= target + 1`.

So we can represent the state using `dp[i][last][cnt]`

Now we need to think about the transition between the states. It's quite straight forward:

* If `house[i]` is already painted, we just skip it so `dp[i][last][cnt] = dp[i + 1][H[i]][H[i] == last ? cnt : (cnt + 1)]`.
* Otherwise, we just try colors from `1` to `N`, and store the best option in `dp[i][last][cnt]`.

```
dp[i][last][cnt] = dp[i + 1][H[i]][H[i] == last ? cnt : (cnt + 1)]                                     // If house[i] > 0
                 = min( cost[i][j] + dp[i + 1][j + 1][j + 1 == last ? cnt : (cnt + 1)] | 0 <= j < N )  // If house[i] == 0
```

We initialize `dp` array using `-1` which means unvisited.

For invalid states, like `cnt > T` or `i == M && cnt != T`, we mark the corresponding `dp` value as `Infinity`.

The answer is `dp[0][0][0]`.

```cpp
// OJ: https://leetcode.com/problems/paint-house-iii/
// Author: github.com/lzl124631x
// Time: O(N^2 * MT)
// Space: O(MNT)
class Solution {
    vector<int> H;
    vector<vector<int>> C;
    int M, N, T, INF = 1e6;
    vector<vector<vector<int>>> memo;
    int dp(int i, int last, int cnt) {
        if (cnt > T) return INF;
        if (i == M) return cnt == T ? 0 : INF;
        if (memo[i][last][cnt] != -1) return memo[i][last][cnt];
        if (H[i]) return memo[i][last][cnt] = dp(i + 1, H[i], H[i] == last ? cnt : (cnt + 1));
        int ans = INF;
        for (int j = 0; j < N; ++j) ans = min(ans, C[i][j] + dp(i + 1, j + 1, j + 1 == last ? cnt : (cnt + 1)));
        return memo[i][last][cnt] = ans;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        H = houses, C = cost, M = m, N = n, T = target;
        memo.assign(M, vector<vector<int>>(N + 1, vector<int>(T + 1, -1)));
        int ans = dp(0, 0, 0);
        return ans == INF ? -1 : ans;
    }
};
```

## Solution 2. Bottom-up DP

Let `dp[i][last][cnt]` be the answer to the sub-problem on the houses in range `[i, M)` and `last` is the color of the `i - 1`-th house, and `cnt` is the number of neighbors existed before `i - 1`-th house. `0 <= i < M`, `1 <= last <= N`, `0 <= cnt <= M`.

For `dp[i][last][cnt]`, we have the following options:
* If `houses[i] > 0`, `dp[i][last][cnt] = dp[i + 1][houses[i]][ houses[i] == last ? cnt : (cnt + 1) ]`.
* Otherwise, we try different colors for the `i`-th house, `dp[i][last][cnt] = min( dp[i + 1][j][ j == last ? cnt : (cnt + 1) ] + cost[i][j - 1] | 1 <= j <= N )`.

```
dp[i][last][cnt] = dp[i + 1][houses[i]][ houses[i] == last ? cnt : (cnt + 1) ]         // If houses[i] > 0
                 = min( dp[i + 1][j][ j == last ? cnt : (cnt + 1) ] + cost[i][j - 1] | 1 <= j <= N )    // If houses[i] == 0
dp[M][last][target] = 0  where 0 < last <= N
```

The `dp` array are initialized with value `Infinity`.

```cpp
// OJ: https://leetcode.com/problems/paint-house-iii/
// Author: github.com/lzl124631x
// Time: O(N^2 * MT)
// Space: O(MNT)
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int INF = 1e6;
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(target + 2, INF)));
        for (int last = 0; last <= n; ++last) dp[m][last][target] = 0;
        for (int i = m - 1; i >= 0; --i) {
            for (int last = 0; last <= n; ++last) {
                for (int cnt = 0; cnt <= target; ++cnt) {
                    if (houses[i]) dp[i][last][cnt] = dp[i + 1][houses[i]][houses[i] == last ? cnt : (cnt + 1)];
                    else {
                        for (int j = 1; j <= n; ++j) dp[i][last][cnt] = min(dp[i][last][cnt], dp[i + 1][j][j == last ? cnt : (cnt + 1)] + cost[i][j - 1]);
                    }
                }
            }
        }
        return dp[0][0][0] == INF ? -1 : dp[0][0][0];
    }
};
```