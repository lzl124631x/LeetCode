# [1473. Paint House III (Hard)](https://leetcode.com/problems/paint-house-iii/)

<p>There is a row of <code>m</code> houses in a small city, each house must be painted with one of the <code>n</code> colors (labeled from <code>1</code> to <code>n</code>), some houses that have been painted last summer should not be painted again.</p>

<p>A neighborhood is a maximal group of continuous houses that are painted with the same color.</p>

<ul>
	<li>For example: <code>houses = [1,2,2,3,3,2,1,1]</code> contains <code>5</code> neighborhoods <code>[{1}, {2,2}, {3,3}, {2}, {1,1}]</code>.</li>
</ul>

<p>Given an array <code>houses</code>, an <code>m x n</code> matrix <code>cost</code> and an integer <code>target</code> where:</p>

<ul>
	<li><code>houses[i]</code>: is the color of the house <code>i</code>, and <code>0</code> if the house is not painted yet.</li>
	<li><code>cost[i][j]</code>: is the cost of paint the house <code>i</code> with the color <code>j + 1</code>.</li>
</ul>

<p>Return <em>the minimum cost of painting all the remaining houses in such a way that there are exactly</em> <code>target</code> <em>neighborhoods</em>. If it is not possible, return <code>-1</code>.</p>

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
	<li><code>1 &lt;= target &lt;= m</code></li>
	<li><code>0 &lt;= houses[i] &lt;= n</code></li>
	<li><code>1 &lt;= cost[i][j] &lt;= 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Top-down DP

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

* If `house[i]` is already painted, we just skip it so `dp[i][last][cnt] = dp[i + 1][H[i]][cnt + (H[i] != last)]`.
* Otherwise, we just try colors from `1` to `N`, and store the best option in `dp[i][last][cnt]`.

```
dp[i][last][cnt] = dp[i + 1][H[i]][cnt + (H[i] != last)]                                     // If house[i] > 0
                 = min( cost[i][j] + dp[i + 1][j + 1][cnt + (j + 1 != last)] | 0 <= j < N )  // If house[i] == 0
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
public:
    int minCost(vector<int>& H, vector<vector<int>>& C, int m, int n, int target) {
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n + 1, vector<int>(target + 1, -1)));
        function<int(int, int, int)> dp = [&](int i, int j, int k) {
            if (k > target) return INT_MAX;
            if (i == m) return k == target ? 0 : INT_MAX;
            if (memo[i][j][k] != -1) return memo[i][j][k];
            if (H[i]) return memo[i][j][k] = dp(i + 1, H[i], k + (j != H[i]));
            int ans = INT_MAX;
            for (int t = 1; t <= n; ++t) {
                int next = dp(i + 1, t, k + (j != t));
                if (next != INT_MAX) ans = min(ans, next + C[i][t - 1]);
            }
            return memo[i][j][k] = ans;
        };
        int ans = dp(0, 0, 0);
        return ans == INT_MAX ? -1 : ans;
    }
};
```

## Solution 2. Bottom-up DP

Let `dp[i+1][j][k]` be the min cost if we paint `houses[0]~houses[i]`, `j` is the painted color of the last house (i.e. `houses[i]`), and `k` is the number of neighborhoods. (`0 <= i < m, 0 <= j <= n, 0 <= k <= target`).

For `dp[i+1][j][k]`, we try different colors `t` for the previous house.

If `houses[i] == 0`:

```
dp[i+1][j][k] = min( dp[i][t][k-(t!=j)] + cost[i][j] | 0 <= t < n ) 
```

If `houses[i] != 0`:

```
dp[i+1][j][k] = min( dp[i][t][k-(t!=j)] | 0 <= t < n ) // if j == houses[i] 
              = Infinity                               // if j != houses[i]
```

Initialization / Trivial case:

```
dp[0][0][0] = 0
// other values are initialized as Infinity
```

The answer is `min( dp[m][j][target] | 1 <= j <= n )`.

```cpp
// OJ: https://leetcode.com/problems/paint-house-iii/
// Author: github.com/lzl124631x
// Time: O(N^2 * MT)
// Space: O(MNT)
class Solution {
public:
    int minCost(vector<int>& H, vector<vector<int>>& C, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(target + 1, INT_MAX)));
        dp[0][0][0] = 0;
        for (int i = 0; i < m; ++i) { // i-th house
            for (int j = 1; j <= n; ++j) { // painting i-th house with color `j`
                if (H[i] && j != H[i]) continue; // If `house[i]` has color already and it's different from color `j`, skip
                for (int k = 1; k <= target; ++k) { // we have `k` neighborhoods
                    for (int t = 0; t <= n; ++t) { // try different colors for houses[i-1]
                        if (dp[i][t][k - (j != t)] == INT_MAX) continue;
                        dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][t][k - (j != t)] + (H[i] ? 0 : C[i][j - 1]));
                    }
                }
            }
        }
        int ans = INT_MAX;
        for (int j = 1; j <= n; ++j) ans = min(ans, dp[m][j][target]);
        return ans == INT_MAX ? -1 : ans;
    }
};
```

## Solution 3. Bottom-up DP with Space Optimization

Since `dp[i+1][?][?]` only depends on `dp[i][?][?]`, we can reduce the space complexity from `O(MNT)` to `O(NT)`.

```cpp
// OJ: https://leetcode.com/problems/paint-house-iii/
// Author: github.com/lzl124631x
// Time: O(N^2 * MT)
// Space: O(NT)
class Solution {
public:
    int minCost(vector<int>& H, vector<vector<int>>& C, int m, int n, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 0; i < m; ++i) {
            vector<vector<int>> next(n + 1, vector<int>(target + 1, INT_MAX));
            for (int j = 1; j <= n; ++j) {
                if (H[i] && j != H[i]) continue;
                for (int k = 1; k <= target; ++k) {
                    for (int t = 0; t <= n; ++t) {
                        if (dp[t][k - (j != t)] == INT_MAX) continue;
                        next[j][k] = min(next[j][k], dp[t][k - (j != t)] + (H[i] ? 0 : C[i][j - 1]));
                    }
                }
            }
            swap(next, dp);
        }
        int ans = INT_MAX;
        for (int j = 1; j <= n; ++j) ans = min(ans, dp[j][target]);
        return ans == INT_MAX ? -1 : ans;
    }
};
```