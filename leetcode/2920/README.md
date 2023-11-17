# [2920. Maximum Points After Collecting Coins From All Nodes (Hard)](https://leetcode.com/problems/maximum-points-after-collecting-coins-from-all-nodes)

<p>There exists an undirected tree rooted at node <code>0</code> with <code>n</code> nodes labeled from <code>0</code> to <code>n - 1</code>. You are given a 2D <strong>integer</strong> array <code>edges</code> of length <code>n - 1</code>, where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is an edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> in the tree. You are also given a <strong>0-indexed</strong> array <code>coins</code> of size <code>n</code> where <code>coins[i]</code> indicates the number of coins in the vertex <code>i</code>, and an integer <code>k</code>.</p>

<p>Starting from the root, you have to collect all the coins such that the coins at a node can only be collected if the coins of its ancestors have been already collected.</p>

<p>Coins at <code>node<sub>i</sub></code> can be collected in one of the following ways:</p>

<ul>
	<li>Collect all the coins, but you will get <code>coins[i] - k</code> points. If <code>coins[i] - k</code> is negative then you will lose <code>abs(coins[i] - k)</code> points.</li>
	<li>Collect all the coins, but you will get <code>floor(coins[i] / 2)</code> points. If this way is used, then for all the <code>node<sub>j</sub></code> present in the subtree of <code>node<sub>i</sub></code>, <code>coins[j]</code> will get reduced to <code>floor(coins[j] / 2)</code>.</li>
</ul>

<p>Return <em>the <strong>maximum points</strong> you can get after collecting the coins from <strong>all</strong> the tree nodes.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/09/18/ex1-copy.png" style="width: 60px; height: 316px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem;" />
<pre>
<strong>Input:</strong> edges = [[0,1],[1,2],[2,3]], coins = [10,10,3,3], k = 5
<strong>Output:</strong> 11                        
<strong>Explanation:</strong> 
Collect all the coins from node 0 using the first way. Total points = 10 - 5 = 5.
Collect all the coins from node 1 using the first way. Total points = 5 + (10 - 5) = 10.
Collect all the coins from node 2 using the second way so coins left at node 3 will be floor(3 / 2) = 1. Total points = 10 + floor(3 / 2) = 11.
Collect all the coins from node 3 using the second way. Total points = 11 + floor(1 / 2) = 11.
It can be shown that the maximum points we can get after collecting coins from all the nodes is 11. 
</pre>

<p><strong class="example">Example 2:</strong></p>
<strong class="example"> <img alt="" src="https://assets.leetcode.com/uploads/2023/09/18/ex2.png" style="width: 140px; height: 147px; padding: 10px; background: #fff; border-radius: .5rem;" /></strong>

<pre>
<strong>Input:</strong> edges = [[0,1],[0,2]], coins = [8,4,4], k = 0
<strong>Output:</strong> 16
<strong>Explanation:</strong> 
Coins will be collected from all the nodes using the first way. Therefore, total points = (8 - 0) + (4 - 0) + (4 - 0) = 16.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == coins.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code><font face="monospace">0 &lt;= coins[i] &lt;= 10<sup>4</sup></font></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code><font face="monospace">0 &lt;= edges[i][0], edges[i][1] &lt; n</font></code></li>
	<li><code><font face="monospace">0 &lt;= k &lt;= 10<sup>4</sup></font></code></li>
</ul>


**Companies**:
[DE Shaw](https://leetcode.com/company/de-shaw)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation), [Tree](https://leetcode.com/tag/tree), [Depth-First Search](https://leetcode.com/tag/depth-first-search)

**Hints**:
* Let <code>dp[x][t]</code> be the maximum points we can get from the subtree rooted at node <code>x</code> and the second operation has been used <code>t</code> times in its ancestors.
* Note that the value of each <code>node <= 10<sup>4</sup></code>, so when <code>t >= 14</code> <code>dp[x][t]</code> is always <code>0</code>.
* General equation will be: <code>dp[x][t] = max((coins[x] >> t) - k + sigma(dp[y][t]), (coins[x] >> (t + 1)) + sigma(dp[y][t + 1]))</code> where nodes denoted by <code>y</code> in the sigma, are the direct children of node <code>x</code>.

## Solution 1. DP

Let `dp[u][i]` be the max score at node `u` if we've done `i` halves in the ancestor nodes.

```
dp[u][i] = max(first[i], second[i])
```

where `first[i]`/`second[i]` is the maximum score we can get with the first/second operation at node `u`.

```
first[i] = (A[u] >> i) - k + SUM( dp[v][i] | v is neighbor of u )
second[i] = (A[u] >> (i + 1)) + SUM( dp[v][i + 1] | v is neighbor of u )
```

The answer is `dp[0][0]`

```cpp
// OJ: https://leetcode.com/problems/maximum-points-after-collecting-coins-from-all-nodes
// Author: github.com/lzl124631x
// Time: O(N * log(max(A)))
// Space: O(N * log(max(A)))
class Solution {
public:
    int maximumPoints(vector<vector<int>>& E, vector<int>& A, int k) {
        int N = A.size();
        vector<vector<int>> G(N), dp(N, vector<int>(13));
        for (auto &e : E) {
            int u = e[0], v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        function<void(int, int)> dfs = [&](int u, int prev) {
            vector<int> first(13), second(13);
            for (int i = 0; i <= 12; ++i) {
                first[i] = (A[u] >> i) - k;
                second[i] = (A[u] >> (i + 1));
            }
            for (int v : G[u]) {
                if (v == prev) continue;
                dfs(v, u);
                for (int i = 0; i <= 12; ++i) first[i] += dp[v][i];
                for (int i = 0; i <= 11; ++i) second[i] += dp[v][i + 1];
            }
            for (int i = 0; i <= 12; ++i) dp[u][i] = max(first[i], second[i]);
        };
        dfs(0, -1);
        return dp[0][0];
    }
};
```

## Solution 2. DP

Similar to Solution 1, but we directly start from `dp[0][0]`.

```cpp
// OJ: https://leetcode.com/problems/maximum-points-after-collecting-coins-from-all-nodes
// Author: github.com/lzl124631x
// Time: O(N * log(max(A)))
// Space: O(N * log(max(A)))
class Solution {
public:
    int maximumPoints(vector<vector<int>>& E, vector<int>& A, int k) {
        int N = A.size();
        vector<vector<int>> G(N), dp(N, vector<int>(13, -1));
        for (auto &e : E) {
            int u = e[0], v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        function<int(int, int, int)> dfs = [&](int u, int prev, int cnt) {
            if (cnt > 12) return 0;
            if (dp[u][cnt] != -1) return dp[u][cnt];
            int first = (A[u] >> cnt) - k, second = (A[u] >> (cnt + 1));
            for (int v : G[u]) {
                if (v == prev) continue;
                first += dfs(v, u, cnt);
                second += dfs(v, u, cnt + 1);
            }
            return dp[u][cnt] = max(first, second);
        };
        return dfs(0, -1, 0);
    }
};
```