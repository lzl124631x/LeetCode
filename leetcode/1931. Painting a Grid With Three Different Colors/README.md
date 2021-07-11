# [1931. Painting a Grid With Three Different Colors (Hard)](https://leetcode.com/problems/painting-a-grid-with-three-different-colors/)

<p>You are given two integers <code>m</code> and <code>n</code>. Consider an <code>m x n</code> grid where each cell is initially white. You can paint each cell <strong>red</strong>, <strong>green</strong>, or <strong>blue</strong>. All cells <strong>must</strong> be painted.</p>

<p>Return<em> the number of ways to color the grid with <strong>no two adjacent cells having the same color</strong></em>. Since the answer can be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/22/colorthegrid.png" style="width: 200px; height: 50px;">
<pre><strong>Input:</strong> m = 1, n = 1
<strong>Output:</strong> 3
<strong>Explanation:</strong> The three possible colorings are shown in the image above.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/22/copy-of-colorthegrid.png" style="width: 321px; height: 121px;">
<pre><strong>Input:</strong> m = 1, n = 2
<strong>Output:</strong> 6
<strong>Explanation:</strong> The six possible colorings are shown in the image above.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> m = 5, n = 5
<strong>Output:</strong> 580986
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m &lt;= 5</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>


**Similar Questions**:
* [Number of Ways to Paint N × 3 Grid (Hard)](https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/)

## Solution 1. DP

Since `m` is at most `5`, we can generate all the valid vectors of length `m` as columns. We at most need to visit `3^m` states. Assume `V` of them are valid.

Then we generate the valid transitions between the column vectors, which takes `O(V^2 * M)` time.

Eventually, we use DP to get the count.

Let `dp[len][state]` be the count of valid matrix with `state` as the last column and `len` columns.

```
dp[len][u] = SUM( dp[len - 1][v] | `u` and `v` are two neighbor states )
dp[1][u] = 1
```

The answer is `SUM( dp[N][u] | u is a valid state )`.

```cpp
// OJ: https://leetcode.com/problems/painting-a-grid-with-three-different-colors/
// Author: github.com/lzl124631x
// Time: O(V^2 * M + VNM) where V is the count of valid column vectors
// Space: O(V^2)
class Solution {
    vector<unordered_map<int, long>> dp;
    long mod = 1e9 + 7;
    vector<string> states;
    vector<vector<int>> G;
    void getStates(int len, int prev, string &s) {
        if (s.size() == len) {
            states.push_back(s);
            return;
        }
        for (int j = 0; j < 3; ++j) {
            if (prev == j) continue;
            s += '0' + j;
            getStates(len, j, s);
            s.pop_back();
        }
    }
    bool areNeighbors(string &a, string &b) {
        for (int i = 0; i < a.size(); ++i)  {
            if (a[i] == b[i]) return false;
        }
        return true;
    }
    long dfs(int len, int u) {
        if (len == 1) return 1;
        if (dp[len].count(u)) return dp[len][u];
        long ans = 0;
        for (int v : G[u]) {
            ans = (ans + dfs(v, len - 1)) % mod;
        }
        return dp[len][u] = ans;
    }
public:
    int colorTheGrid(int m, int n) {
        string s;
        getStates(m, -1, s);
        int N = states.size();
        G.assign(N, {});
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (areNeighbors(states[i], states[j])) {
                    G[i].push_back(j);
                }
            }
        }
        long ans = 0;
        dp.assign(n + 1, {});
        for (int i = 0; i < N; ++i) ans = (ans + dfs(n, i)) % mod;
        return ans;
    }
};
```