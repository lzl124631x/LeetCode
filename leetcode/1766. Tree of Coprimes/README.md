# [1766. Tree of Coprimes (Hard)](https://leetcode.com/problems/tree-of-coprimes/)

<p>There is a tree (i.e.,&nbsp;a connected, undirected graph that has no cycles) consisting of <code>n</code> nodes numbered from <code>0</code> to <code>n - 1</code> and exactly <code>n - 1</code> edges. Each node has a value associated with it, and the <strong>root</strong> of the tree is node <code>0</code>.</p>

<p>To represent this tree, you are given an integer array <code>nums</code> and a 2D array <code>edges</code>. Each <code>nums[i]</code> represents the <code>i<sup>th</sup></code> node's value, and each <code>edges[j] = [u<sub>j</sub>, v<sub>j</sub>]</code> represents an edge between nodes <code>u<sub>j</sub></code> and <code>v<sub>j</sub></code> in the tree.</p>

<p>Two values <code>x</code> and <code>y</code> are <strong>coprime</strong> if <code>gcd(x, y) == 1</code> where <code>gcd(x, y)</code> is the <strong>greatest common divisor</strong> of <code>x</code> and <code>y</code>.</p>

<p>An ancestor of a node <code>i</code> is any other node on the shortest path from node <code>i</code> to the <strong>root</strong>. A node is <strong>not </strong>considered an ancestor of itself.</p>

<p>Return <em>an array </em><code>ans</code><em> of size </em><code>n</code>, <em>where </em><code>ans[i]</code><em> is the closest ancestor to node </em><code>i</code><em> such that </em><code>nums[i]</code> <em>and </em><code>nums[ans[i]]</code> are <strong>coprime</strong>, or <code>-1</code><em> if there is no such ancestor</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2021/01/06/untitled-diagram.png" style="width: 191px; height: 281px;"></strong></p>

<pre><strong>Input:</strong> nums = [2,3,3,2], edges = [[0,1],[1,2],[1,3]]
<strong>Output:</strong> [-1,0,0,1]
<strong>Explanation:</strong> In the above figure, each node's value is in parentheses.
- Node 0 has no coprime ancestors.
- Node 1 has only one ancestor, node 0. Their values are coprime (gcd(2,3) == 1).
- Node 2 has two ancestors, nodes 1 and 0. Node 1's value is not coprime (gcd(3,3) == 3), but node 0's
  value is (gcd(2,3) == 1), so node 0 is the closest valid ancestor.
- Node 3 has two ancestors, nodes 1 and 0. It is coprime with node 1 (gcd(3,2) == 1), so node 1 is its
  closest valid ancestor.
</pre>

<p><strong>Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/01/06/untitled-diagram1.png" style="width: 441px; height: 291px;"></p>

<pre><strong>Input:</strong> nums = [5,6,10,2,3,6,15], edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
<strong>Output:</strong> [-1,0,-1,0,0,0,-1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>nums.length == n</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[j].length == 2</code></li>
	<li><code>0 &lt;= u<sub>j</sub>, v<sub>j</sub> &lt; n</code></li>
	<li><code>u<sub>j</sub> != v<sub>j</sub></code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

## Solution 1. DFS

### Complexity Analysis

Collecting all the unique numbers takes `O(N)` time and `O(50) = O(1)` space.

Generating the `cops` takes `O(50 * 50) = O(1)` time.

Generating the graph `G` takes `O(N)` time and `O(N)` space.

For each DFS invocation, traversing all the `cops` to get the maximum level takes `O(50) = O(1)` time.

The maximum depth of the DFS is `O(N)`, so this take `O(N)` time and `O(N)` space.

Overall, this solution takes `O(N)` time and `O(N)` space.

```cpp
// OJ: https://leetcode.com/problems/tree-of-coprimes/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/tree-of-coprimes/discuss/1074770/C%2B%2B-Save-the-cops
class Solution {
    pair<int, int> maxLevel[51]; // level, index
    vector<int> cops[51], ans;
    vector<vector<int>> G;
    void dfs(vector<int> &A, int i, int parent = 0, int lv = 0) {
        int maxLv = -1;
        for (int cop : cops[A[i]]) { // traverse each co-prime of `A[i]` and find the one with the maximum level
            auto [level, index] = maxLevel[cop];
            if (level > maxLv) {
                maxLv = level;
                ans[i] = index;
            }
        }
        auto prev = maxLevel[A[i]];
        maxLevel[A[i]] = { lv, i }; // update the current level as the maximum level of A[i]
        for (int j : G[i]) {
            if (j != parent) dfs(A, j, i, lv + 1);
        }
        maxLevel[A[i]] = prev; // backtrack
    }
public:
    vector<int> getCoprimes(vector<int>& A, vector<vector<int>>& E) {
        unordered_set<int> s(begin(A), end(A));  // collect all the unique numbers
        for (int n : s) {
            for (int m : s) {
                if (gcd(n, m) == 1) cops[n].push_back(m); // for each number, save all of its co-primes into `cops`
            }
        }
        G.assign(A.size(), {});
        for (auto &e : E) {
            int u = e[0], v = e[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        ans.assign(A.size(), -1);
        memset(maxLevel, -1, sizeof(maxLevel));
        dfs(A, 0);
        return ans;
    }
};
```