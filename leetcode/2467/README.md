# [2467. Most Profitable Path in a Tree (Medium)](https://leetcode.com/problems/most-profitable-path-in-a-tree)

<p>There is an undirected tree with <code>n</code> nodes labeled from <code>0</code> to <code>n - 1</code>, rooted at node <code>0</code>. You are given a 2D integer array <code>edges</code> of length <code>n - 1</code> where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is an edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> in the tree.</p>

<p>At every node <code>i</code>, there is a gate. You are also given an array of even integers <code>amount</code>, where <code>amount[i]</code> represents:</p>

<ul>
	<li>the price needed to open the gate at node <code>i</code>, if <code>amount[i]</code> is negative, or,</li>
	<li>the cash reward obtained on opening the gate at node <code>i</code>, otherwise.</li>
</ul>

<p>The game goes on as follows:</p>

<ul>
	<li>Initially, Alice is at node <code>0</code> and Bob is at node <code>bob</code>.</li>
	<li>At every second, Alice and Bob <b>each</b> move to an adjacent node. Alice moves towards some <strong>leaf node</strong>, while Bob moves towards node <code>0</code>.</li>
	<li>For <strong>every</strong> node along their path, Alice and Bob either spend money to open the gate at that node, or accept the reward. Note that:
	<ul>
		<li>If the gate is <strong>already open</strong>, no price will be required, nor will there be any cash reward.</li>
		<li>If Alice and Bob reach the node <strong>simultaneously</strong>, they share the price/reward for opening the gate there. In other words, if the price to open the gate is <code>c</code>, then both Alice and Bob pay&nbsp;<code>c / 2</code> each. Similarly, if the reward at the gate is <code>c</code>, both of them receive <code>c / 2</code> each.</li>
	</ul>
	</li>
	<li>If Alice reaches a leaf node, she stops moving. Similarly, if Bob reaches node <code>0</code>, he stops moving. Note that these events are <strong>independent</strong> of each other.</li>
</ul>

<p>Return<em> the <strong>maximum</strong> net income Alice can have if she travels towards the optimal leaf node.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/10/29/eg1.png" style="width: 275px; height: 275px;" />
<pre>
<strong>Input:</strong> edges = [[0,1],[1,2],[1,3],[3,4]], bob = 3, amount = [-2,4,2,-4,6]
<strong>Output:</strong> 6
<strong>Explanation:</strong> 
The above diagram represents the given tree. The game goes as follows:
- Alice is initially on node 0, Bob on node 3. They open the gates of their respective nodes.
  Alice&#39;s net income is now -2.
- Both Alice and Bob move to node 1. 
&nbsp; Since they reach here simultaneously, they open the gate together and share the reward.
&nbsp; Alice&#39;s net income becomes -2 + (4 / 2) = 0.
- Alice moves on to node 3. Since Bob already opened its gate, Alice&#39;s income remains unchanged.
&nbsp; Bob moves on to node 0, and stops moving.
- Alice moves on to node 4 and opens the gate there. Her net income becomes 0 + 6 = 6.
Now, neither Alice nor Bob can make any further moves, and the game ends.
It is not possible for Alice to get a higher net income.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/10/29/eg2.png" style="width: 250px; height: 78px;" />
<pre>
<strong>Input:</strong> edges = [[0,1]], bob = 1, amount = [-7280,2350]
<strong>Output:</strong> -7280
<strong>Explanation:</strong> 
Alice follows the path 0-&gt;1 whereas Bob follows the path 1-&gt;0.
Thus, Alice opens the gate at node 0 only. Hence, her net income is -7280. 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>edges</code> represents a valid tree.</li>
	<li><code>1 &lt;= bob &lt; n</code></li>
	<li><code>amount.length == n</code></li>
	<li><code>amount[i]</code> is an <strong>even</strong> integer in the range <code>[-10<sup>4</sup>, 10<sup>4</sup>]</code>.</li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google), [Intuit](https://leetcode.com/company/intuit)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Tree](https://leetcode.com/tag/tree), [Depth-First Search](https://leetcode.com/tag/depth-first-search), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search), [Graph](https://leetcode.com/tag/graph)

**Similar Questions**:
* [Snakes and Ladders (Medium)](https://leetcode.com/problems/snakes-and-ladders)

**Hints**:
* Bob travels along a fixed path (from node “bob” to node 0).
* Calculate Alice’s distance to each node via DFS.
* We can calculate Alice’s score along a path ending at some node easily using Hints 1 and 2.

## Solution 1.

1. DFS from Bob and adjust the amounts along the path from `0` to `bob`.
2. DFS from Alice and calculate the maximum path sum to leaves.

```cpp
// OJ: https://leetcode.com/problems/most-profitable-path-in-a-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& E, int bob, vector<int>& A) {
        int N = A.size(), pathLength = -1;
        vector<vector<int>> G(N);
        for (auto &e : E) {
            int u = e[0], v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<bool> seen(N);
        function<void(int, int)> adjustAmounts = [&](int u, int level) {
            if (u == 0) {
                pathLength = level + 1;
                return;
            }
            seen[u] = true;
            for (int v : G[u]) {
                if (seen[v]) continue;
                adjustAmounts(v, level + 1);
                if (pathLength != -1) break;
            }
            if (pathLength != -1) {
                if (pathLength / 2 == level && pathLength % 2) A[u] /= 2;
                else if (pathLength / 2 > level) A[u] = 0;
            }
        };
        adjustAmounts(bob, 0);
        seen.assign(N, false);
        function<int(int, int)> dfs = [&](int u, int score) {
            score += A[u];
            int mx = INT_MIN, cnt = 0;
            seen[u] = true;
            for (int v : G[u]) {
                if (seen[v]) continue;
                mx = max(mx, dfs(v, score));
                ++cnt;
            }
            if (cnt == 0) return score;
            return mx;
        };
        return dfs(0, 0);
    }
};
```

## Solution 2. DFS

Similar to solution 1, but when DFS from Bob, we just calculate `distFromBob`. And then we calculate the optimal income we can get when DFS from Alice.

```cpp
// OJ: https://leetcode.com/problems/most-profitable-path-in-a-tree
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& E, int bob, vector<int>& A) {
        int N = A.size();
        vector<vector<int>> G(N);
        for (auto &e : E) {
            int u = e[0], v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> distFromBob(N, INT_MAX);
        function<bool(int, int, int)> calcDistFromBob = [&](int u, int prev, int d) {
            distFromBob[u] = d;
            if (u == 0) return true;
            for (int v : G[u]) {
                if (v == prev) continue;
                if (calcDistFromBob(v, u, d + 1)) return true;
            }
            distFromBob[u] = INT_MAX;
            return false;
        };
        calcDistFromBob(bob, -1, 0);
        function<int(int, int, int)> dfs = [&](int u, int prev, int d) {
            int mx = INT_MIN;
            for (int v : G[u]) {
                if (v == prev) continue;
                mx = max(mx, dfs(v, u, d + 1));
            }
            int val = d == distFromBob[u] ? A[u] / 2 : (d < distFromBob[u] ? A[u] : 0);
            return mx == INT_MIN ? val : val + mx; 
        };
        return dfs(0, -1, 0);
    }
};
```